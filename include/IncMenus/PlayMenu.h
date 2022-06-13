#pragma once

#include "GameMenu.h"
#include "Data.h"

class Data;

class PlayMenu : public GameMenu {
public:
    PlayMenu(unsigned playBackground, unsigned InGameMenuBackground, const Vector2f& pos);

    void draw(RenderTarget& window, const Vector2f& userCarPos) override;

    void handleClick(const Vector2f& pos, vector<bool>& windows, size_t currWindow, bool* running) override;

    void pauseGame() {}

    void setPause(bool mode) { m_pressPause = mode; }

    void handlePressPause();

    void handlePressHome(vector<bool>&, size_t);

    void handlePressMusic();

private:
    Sprite m_menuBackground;
    bool m_pressPause = false;
    bool m_music = true;
};
