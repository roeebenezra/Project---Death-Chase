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

    RenderWindow m_gameWindow = {VideoMode(2300, 1800), "Death Chase"};
    sf::Sprite m_gameImage;
    std::vector<sf::View> m_views;
    Data m_data;
    std::unique_ptr<b2World> m_world;
    bool m_userMoved;
};
