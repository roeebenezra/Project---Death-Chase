#pragma once

#include "GameMenu.h"
#include "Data.h"

class Data;

class PlayMenu : public GameMenu {
public:
    PlayMenu(unsigned playBackground, unsigned InGameMenuBackground, const Vector2f &pos);

    void draw(RenderTarget &window, const Vector2f &userCarPos) override;

    void handleClick(const Vector2f &pos, vector<bool> &windows, size_t currWindow, bool *running) override;

    void setPause(bool mode) { m_pressPause = mode; }

    void handlePressPause();

    void handlePressHome(vector<bool> &, size_t);

    void handlePressMusic();

    void handlePressRestart();

    void coinsCounter() override { m_coins++; }

    void nextLevel() override { m_level++; }

    void resetCoins() override;

    void updateTextString(const TEXTS &, const unsigned &, const unsigned &) override;

private:
    void setPlayMenuTexts();

    Text createText(Vector2f, unsigned, const string &, Color) const;

    Sprite m_menuBackground;
    Sprite m_secondBackground;
    vector<Text> m_playMenuTexts;
    vector<string> Texts = {"Level: ", "$ "};
    unsigned m_coins = 0;
    unsigned m_level = 0;
    bool m_music = true;
};
