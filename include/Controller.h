#pragma once

#include "macros.h"
#include "Data.h"
#include "Gui.h"
#include "MyContactListener.h"

class Controller {
public:
    Controller();

    void run();

private:
    void box2dStep(MyContactListener *);

    void handleEvents();

    void handleData();

    void handleReturnToMenu();

    void keyboardPressed(const sf::Event &);

    void draw();

    void drawPlay();

    void exitGame(const Event &);

    RenderWindow m_gameWindow = {VideoMode(1600, 900), "Death Chase"};
    Data m_data;
    Gui m_gui;
    bool m_userMoved = false;
    bool m_running = true;
};