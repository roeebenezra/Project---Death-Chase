#pragma once

#include "GameMenu.h"

class OpenMenu : public GameMenu {
public:
    OpenMenu(unsigned Background, unsigned HowToPlay, Vector2f pos);

    void draw(RenderTarget& window, const Vector2f& userCarPos) override;

    void drawHowToPlay(RenderTarget& window);

    void handleClick(const Vector2f& pos, vector<bool>& windows, size_t currWindow, bool* running) override;

    void setHowToPlay(bool mode) { m_pressHowToPlay = mode; }

private:
//    vector<unique_ptr<Button>> m_buttons;
    Sprite m_howToPlay;
    bool m_pressHowToPlay = false;
};
