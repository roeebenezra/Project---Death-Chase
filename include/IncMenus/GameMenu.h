#pragma once

#include "macros.h"
#include "IncMenus/Button.h"

//GameMenu
class GameMenu {
public:
    GameMenu(unsigned TextureName, const Vector2f &pos)
            : m_background(Resources::instance().getTexture(TextureName)) {
        m_background.setPosition(pos);
    }

    GameMenu() = default;

    virtual ~GameMenu() = default;

    void add(unique_ptr<Button> button) { m_buttons.emplace_back(move(button)); }

    void draw(RenderTarget &);

    void isMouseOnButton(const Vector2f &pos) {
        for (auto &button: m_buttons)
            button->isMouseOnButton(pos);
    }

    bool isMousePressOnButton(const Vector2f &pos) {
        for (auto &button: m_buttons)
            if (button->isMousePressOnButton(pos))
                return true;
        return false;
    }

    unique_ptr<Button> &getButton(unsigned place) { return m_buttons[place]; }

protected:
    Sprite &getSprite() { return m_background; }

private:
    vector<unique_ptr<Button>> m_buttons;
    Sprite m_background;
};
