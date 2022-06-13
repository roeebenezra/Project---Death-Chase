#include "IncMenus/Button.h"

Button::Button(unsigned TextureName, const Vector2f& pos, const IntRect& rect)
                     : m_button(Resources::instance().getTexture(TextureName), rect),   
                       m_TextureRect(rect)
{
    m_button.setPosition(pos);
}

bool Button::isMousePressOnButton(const Vector2f& pos) {
    if (m_button.getGlobalBounds().contains(pos)) {
        setClickOnButton(true);
        return true;
    }
    else {
        setClickOnButton(false);
        return false;
    }
}

void Button::isMouseOnButton(const Vector2f& pos)
{
    if (m_button.getGlobalBounds().contains(pos))
        setOnButton(true);
    else
        setOnButton(false);
}