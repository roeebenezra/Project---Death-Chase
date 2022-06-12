#pragma once

#include "macros.h"
#include "IncMenus/Button.h"

//GameMenu
class GameMenu {
public:
    GameMenu(unsigned TextureName, const Vector2f &pos);

    GameMenu() = default;

    virtual ~GameMenu() = default;

    void add(unique_ptr<Button> button) { m_buttons.emplace_back(move(button)); }

    virtual void draw(RenderTarget &);

    void isMouseOnButton(const Vector2f &pos);

    virtual bool isMousePressOnButton(const Vector2f &pos) {
        for (auto &button: m_buttons) {
            if (button->isMousePressOnButton(pos))
                return true;
        }
        return false;
    }

    long mousePressButton(const Vector2f &pos) {
        for (auto &button: m_buttons) {
            if (button->isMousePressOnButton(pos)) {
                Resources::instance().playSound(Click);
                return find(m_buttons.begin(), m_buttons.end(), button) - m_buttons.begin() + 1;
            }
        }
        return 0;
    }

    virtual void handleClick(const Vector2f &pos, vector<bool> &windows, size_t currWindow, bool *running) {}

    unique_ptr<Button> &getButton(size_t place) { return m_buttons[place]; }

protected:
    Sprite &getSprite() { return m_background; }

    size_t getNumOfButtons() { return m_buttons.size(); }

private:
    vector<unique_ptr<Button>> m_buttons;
    Sprite m_background;
};
