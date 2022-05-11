#pragma once
#include "macros.h"


class Controller{
public:
    Controller();
    void run();
    void handleEvents();
    void mouseEventPressed(const Event&);
    void mouseEventMoved(const Event&);
    void exitGame(const Event&);

private:
    RenderWindow m_gameWindow = {VideoMode(1200, 950), "Death Chase", Style::Close | Style::Resize};
    View m_view;
};
