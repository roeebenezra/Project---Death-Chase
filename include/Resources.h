#pragma once

#include "macros.h"

class Resources {

public:
    static Resources &instance();

    Resources(const Resources &) = delete;

    void operator=(const Resources &) = delete;

    sf::Texture &getTexture(const int name) { return m_texture[name]; }

private:
    Resources();

    void loadResources();

    std::vector<sf::Sprite> m_sprites;
    std::vector<sf::Texture> m_texture;
//    std::vector<sf::SoundBuffer> m_soundsBuffer;
//    std::vector<sf::Sound> m_sounds;
    sf::Font m_font;
};