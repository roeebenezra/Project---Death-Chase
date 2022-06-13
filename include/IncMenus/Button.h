#include "macros.h"

class Button {
public:
    Button(unsigned TextureName, const Vector2f& pos, const IntRect& rect);

    Button() = default;

    virtual ~Button() = default;

    virtual void draw(RenderTarget &window) = 0;

    virtual bool isMousePressOnButton(const Vector2f& pos);

    virtual void isMouseOnButton(const Vector2f& pos);

    void updatePos(const Vector2f &pos) { m_button.setPosition(pos); }

    void setOnButton(bool mode) { m_isOnButton = mode; }

    bool isOnButton() const { return m_isOnButton; }

    bool isClickOnButton() const { return m_isClickOnButton; }

    void setClickOnButton(bool mode) { m_isClickOnButton = mode; }

    Sprite &getSpriteButton() { return m_button; }

protected:
    IntRect &getTextureRect() { return m_TextureRect; }

private:
    Sprite m_button;
    IntRect m_TextureRect;

    bool m_isOnButton = false;
    bool m_isClickOnButton = false;
};
