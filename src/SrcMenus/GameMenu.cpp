#include "IncMenus/GameMenu.h"

//__________________________________________________________
GameMenu::GameMenu(unsigned TextureName, const Vector2f& pos)
    : m_background(Resources::instance().getTexture(TextureName)) {
    m_background.setPosition(pos);
}

//_________________________________________________________________
void GameMenu::draw(RenderTarget &window, const Vector2f& userCarPos)
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

//_____________________________________________________
bool GameMenu::isMousePressOnButton(const Vector2f& pos) {
    for (auto& button : m_buttons) {
        if (button->isMousePressOnButton(pos))
            return true;
    }
    return false;
}

//_________________________________________________
long GameMenu::mousePressButton(const Vector2f& pos) {
    for (auto& button : m_buttons) {
        if (button->isMousePressOnButton(pos)) {
            Resources::instance().playSoundBuffer(Click);
            return find(m_buttons.begin(), m_buttons.end(), button) - m_buttons.begin() + 1;
        }
    }
    return 0;
}
