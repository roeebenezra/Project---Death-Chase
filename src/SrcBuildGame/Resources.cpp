#include "IncBuildGame/Resources.h"

//_________________________________
Resources::Resources() : m_data(Max) {
    loadResources();
    m_data[Coin] = CoinObject({50, 60}, {0, 0}, {20, 0});
    m_data[Dust] = dustObject({130, 86}, {0, 0}, {25, 0});
    m_data[HealthBar] = carHealthObject({113, 28}, {0, 0}, {0, 5});
    m_data[Explosion] = explosionObject({295, 245}, {0, 0}, {0, 6});
}

//______________________________
Resources &Resources::instance() {
    static auto resource = Resources();
    return resource;
}

//_____________________________
void Resources::loadResources() {
    if (!m_font.loadFromFile(FontFile))
        std::cout << "fail to load font";


    auto soundBuffer = sf::SoundBuffer();
    for (auto& sound : Sounds)
    {
        soundBuffer.loadFromFile(sound);
        m_soundsBuffer.push_back(soundBuffer);
    }

    sf::Texture texture;
    sf::Sprite sprite;

    for (unsigned i = 0; i < TexturesCount; i++) {
        if (!texture.loadFromFile(Textures[i]))
            std::cout << "fail to load " << i << " texture";
        texture.setSmooth(true);
        m_texture.push_back(texture);
        sprite.setTexture(m_texture[i]);
        m_sprites.push_back(sprite);
    }
}

//_____________________________________________
void Resources::playSoundBuffer(const int index) {

    m_soundBuffer.setBuffer(m_soundsBuffer[index]);
    m_soundBuffer.play();
}
//____________________________________________
void Resources::playSoundMusic(const int index) {

    m_soundMusic.setBuffer(m_soundsBuffer[index]);
    m_soundMusic.setLoop(true);
    m_soundMusic.play();
}

//________________________
void Resources::stopSound() {
    m_soundMusic.stop();
}

//____________________________________________________
void Resources::setLoopSound(const int index, bool mode) {
    if (mode) {
        m_soundMusic.setBuffer(m_soundsBuffer[index]);
        m_soundMusic.setLoop(mode);
        m_soundMusic.setVolume(50.0f);
        m_soundMusic.play();
    } else
        stopSound();
}
