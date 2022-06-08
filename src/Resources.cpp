#include "Resources.h"

//____________________
Resources::Resources() {
    loadResources();
}

//____________________________
Resources &Resources::instance() {
    static auto resource = Resources();
    return resource;
}

//_____________________________
void Resources::loadResources() {
    if (!m_font.loadFromFile(FontFile))
        std::cout << "fail to load font";

    sf::SoundBuffer soundBuffer;
    sf::Sound sound;

    for (unsigned i = 0; i < SoundsCount; i++) {
        if (!soundBuffer.loadFromFile(Sounds[i]))
            cout << "fail to load " << i << " sound";
        m_soundsBuffer.push_back(soundBuffer);
        sound.setBuffer(m_soundsBuffer[i]);
        m_sounds.push_back(sound);
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

//___________________________________________
void Resources::playSound(const unsigned sound) {
    m_sounds[sound].play();
    setSoundVol(sound, 50.0f);
}

//___________________________________________
void Resources::stopSound(const unsigned sound) {
    m_sounds[sound].stop();
}

//__________________________________________________
void Resources::playInLoopSound(const unsigned sound) {
    m_sounds[sound].play();
    m_sounds[sound].setLoop(true);
    setSoundVol(sound, 50.0f);
}

//____________________________________________________________
void Resources::setSoundVol(const unsigned sound, float volume) {
    m_sounds[sound].setVolume(volume);
}