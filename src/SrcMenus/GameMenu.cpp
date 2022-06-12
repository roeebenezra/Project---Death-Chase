#include "IncMenus/GameMenu.h"


GameMenu::GameMenu(unsigned TextureName, const Vector2f& pos)
    : m_background(Resources::instance().getTexture(TextureName)) {
    m_background.setPosition(pos);
}

//_____________________________________
void GameMenu::draw(RenderTarget &window)
{
    window.draw(m_background);
    for (auto &button: m_buttons)
        button->draw(window);
}

//________________________________________________
void GameMenu::isMouseOnButton(const Vector2f& pos) {
    for (auto& button : m_buttons)
        button->isMouseOnButton(pos);
}


