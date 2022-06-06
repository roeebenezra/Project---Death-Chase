#include "macros.h"

class Button {
public:
    explicit Button(Sprite &sprite, Vector2f pos) : m_button(sprite) { m_button.setPosition(pos); }

    virtual ~Button() = default;

    virtual void draw(RenderTarget &window) = 0;

protected:
    Sprite &getSprite() { return m_button; }

private:
    Sprite m_button;
};
