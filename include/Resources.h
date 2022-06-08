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

    const sf::Texture &getTexture(const unsigned name) { return m_texture[name]; }

    const AnimationData& animationData(Objects object) { return m_data[object]; }

private:
    Resources();

    void loadResources();

    std::vector<AnimationData> m_data;
    std::vector<sf::Texture> m_texture;
    sf::Font m_font;
};