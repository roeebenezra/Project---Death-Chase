#pragma once

#include "macros.h"
#include "Data.h"
#include "IncMenus/GameMenu.h"

#include "IncMenus/MusicButton.h"
#include "IncMenus/OpenMenu.h"
#include "IncMenus/ChooseVehicleMenu.h"

#include "MyContactListener.h"
#include <memory>

class Controller {

public:
    Controller();

    void run();

private:
    void setView();

    void DataSetup(MyContactListener*);

    void setMenus();

    void drawMenu();

    void handleEvents();

    void mouseEventPressed(const Event &);

    void mouseEventMoved(const Event &);

    void keyboardPressed(const sf::Event &);

    void draw();

    void exitGame(const Event &);

    RenderWindow m_gameWindow = {VideoMode(1600, 900), "Death Chase"};
    std::vector<sf::View> m_views;
    Data m_data;

    Sprite m_image;
    bool m_windows[MenusCount] = {true, false,  false, false, false};
    vector<unique_ptr<GameMenu>> m_menus;
    bool m_userMoved;
};
