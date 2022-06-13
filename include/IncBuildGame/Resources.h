#pragma once

#include "IncAnimation/AnimationData.h"
#include "macros.h"

class Resources {

public:
    enum Objects
    {
        UserCar,
        ComputerCar,
        Dust,
        Coin,
        HealthBar,
        Explosion,
        Max,
    };
    static Resources &instance();

    Resources(const Resources &) = delete;

    void operator=(const Resources &) = delete;

    sf::Sprite &getSprite(const unsigned name) { return m_sprites[name]; }

    sf::Texture &getTexture(const unsigned name) { return m_texture[name]; }

    const AnimationData& animationData(Objects object) { return m_data[object]; }

    void playSound(unsigned);

    void stopSound(unsigned);

    void playInLoopSound(unsigned);

    void setSoundVol(unsigned, float);
private:
    Resources();

    void loadResources();

    sf::Font m_font;
    std::vector<sf::Sprite> m_sprites;
    std::vector<sf::Texture> m_texture;

    std::vector<sf::SoundBuffer> m_soundsBuffer;
    std::vector<sf::Sound> m_sounds;
    std::vector<AnimationData> m_data;

};