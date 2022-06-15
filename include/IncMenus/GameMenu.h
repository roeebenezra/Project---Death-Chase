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

    virtual void draw(RenderTarget &, const Vector2f &);

    void isMouseOnButton(const Vector2f &pos);

    virtual bool isMousePressOnButton(const Vector2f &pos);

    long mousePressButton(const Vector2f &pos);

    virtual void handleClick(const Vector2f &pos, vector<bool> &windows, size_t currWindow, bool *running) {}

    unique_ptr<Button> &getButton(size_t place) { return m_buttons[place]; }

    bool isPause() const { return m_pressPause; }

    void setPause(const bool &pause) { m_pressPause = pause; }

    bool isRestart() const { return m_pressRestart; }

    void setRestart(const bool &restart) { m_pressRestart = restart; }

    virtual void updateTextString(const TEXTS &, const unsigned &, const unsigned &) {}

    virtual void drawEnd(RenderWindow &, const sf::Vector2f &, const std::string &, const Color &) {}

protected:
    Sprite &getSprite() { return m_background; }

    size_t getNumOfButtons() { return m_buttons.size(); }

    vector<unique_ptr<Button>> m_buttons;

    bool m_pressPause = false;
    bool m_pressRestart = false;
private:
    Sprite m_background;
};
