#include "IncMenus/GameMenu.h"

void GameMenu::draw(RenderTarget &window)
{
    window.draw(m_background);
    for (auto &button: m_buttons)
        button->draw(window);
}
