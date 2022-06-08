#include "macros.h"

class Button {
public:
    Button(unsigned TextureName, const Vector2f &pos, const IntRect &rect)
            : m_button(Resources::instance().getTexture(TextureName), rect), m_TextureRect(rect) {
        m_button.setPosition(pos);
    }

    Button() = default;

    virtual ~Button() = default;

    virtual void draw(RenderTarget &window) = 0;

    bool isMousePressOnButton(const Vector2f &pos) {
        if (m_button.getGlobalBounds().contains(pos))
            return true;
        return false;
    }

    void isMouseOnButton(const Vector2f &pos) {
        if (m_button.getGlobalBounds().contains(pos))
            setOnButton();
        else
            setOffButton();
    }

    void updatePos(const Vector2f &pos) {
        getSpriteButton().setPosition(pos);
    }

    void setOnButton() { m_isOnButton = true; }

    void setOffButton() { m_isOnButton = false; }

    bool isOnButton() const { return m_isOnButton; }

protected:
    Sprite &getSpriteButton() { return m_button; }

    IntRect &getTextureRect() { return m_TextureRect; }

private:
    Sprite m_button;
    IntRect m_TextureRect;
    bool m_isOnButton = false;
};

