#pragma once

#include "macros.h"
#include "IncMenus/GameMenu.h"
#include "IncMenus/MusicButton.h"
#include "IncMenus/PauseButton.h"
#include "IncMenus/OpenMenuButton.h"
#include "IncMenus/InGameMenuButton.h"
#include "IncMenus/OpenMenu.h"
#include "IncMenus/ChooseVehicleMenu.h"
#include "IncMenus/PlayMenu.h"
#include "StartMessage.h"

class Gui {

public:
    Gui(sf::RenderWindow &);


    void drawStartMessage(sf::RenderWindow &);

    void setView(sf::RenderWindow &window,
                 float width,
                 float height);

    long CurrMenu();

    void mouseEventPressed(sf::RenderWindow &,
                           const Event &,
                           bool &);

    void mouseEventMoved(const Event &);

    bool currWindowStatus(const unsigned &window) { return m_windows[window]; }

    void drawWindow(sf::RenderWindow &, const sf::Vector2f &);

    bool handlePauseButton(const sf::Keyboard::Key&);

    bool getStartDrawMessage() { m_startMessageDraw.getDrawMessage(); }

    void setStartDrawMessage(const bool &draw) { m_startMessageDraw.setDrawMessage(draw); }

    bool isWindowInOpenGameMenu() { return CurrMenu() == OpenGameMenu; }

private:
    void setIcon(sf::RenderWindow &);

    void setMenus();

    StartMessage m_startMessageDraw;
    vector<bool> m_windows = {true, false, false, false};
    vector<unique_ptr<GameMenu>> m_menus;
};