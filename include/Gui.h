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

    void mouseEventMoved(sf::RenderWindow &, const Event &);

    bool currWindowStatus(const unsigned &window) { return m_windows[window]; }

    void drawWindow(sf::RenderWindow &, const sf::Vector2f &);

    bool handlePauseButton(const sf::Keyboard::Key &);

    bool getStartDrawMessage() { m_startMessageDraw.getDrawMessage(); }

    bool isWindowInOpenGameMenu() { return CurrMenu() == OpenGameMenu; }

    bool isRestart();

    void setRestart(const bool &restart) { m_menus[CurrMenu()]->setRestart(restart); }

    void updateText(const TEXTS &text,
                    const unsigned &num,
                    const unsigned &indexOffset) { m_menus[CurrMenu()]->updateTextString(text, num, indexOffset); }

    void resetStartMessage() { m_startMessageDraw.resetStartMessage(); }

    void drawEnd(RenderWindow &window,
                 const sf::Vector2f &pos,
                 const std::string &text,
                 const Color &color) { m_menus[CurrMenu()]->drawEnd(window, pos, text, color); }

private:
    void setIcon(sf::RenderWindow &);

    void setMenus();

    StartMessage m_startMessageDraw;
    vector<bool> m_windows = {false, true, false, false};
    vector<unique_ptr<GameMenu>> m_menus;
};