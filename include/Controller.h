#pragma once

#include "macros.h"
#include "Data.h"
#include <memory>

class Controller {

public:
    Controller();

    void run();

private:
    void handleEvents();

    void mouseEventPressed(const Event &);

    void mouseEventMoved(const Event &);

    void keyboardPressed(const sf::Event &);

    void draw();

    void exitGame(const Event &);

    RenderWindow m_gameWindow = {VideoMode(1200, 900), "Death Chase", Style::Close | Style::Resize | Style::Fullscreen};
    sf::Sprite m_gameImage;

    Data m_data;
    std::unique_ptr<b2World> m_world;
    bool m_userMoved;
};
