#pragma once
#include "macros.h"
#include "IncMenus/Button.h"

//GameMenu
class GameMenu {
public:
    explicit GameMenu(Sprite &background, Vector2f pos) : m_background(background) { m_background.setPosition(pos); }

    GameMenu() = default;

    virtual ~GameMenu() = default;

    void add(unique_ptr<Button> button) { m_buttons.emplace_back(move(button)); }

    void draw(RenderTarget &);

private:
    vector<unique_ptr<Button>> m_buttons;
    Sprite m_background;
};
