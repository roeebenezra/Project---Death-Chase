#pragma once

#include "GameMenu.h"
#include "Data.h"

class Data;

class PlayMenu : public GameMenu {
public:
    PlayMenu(unsigned playBackground, unsigned InGameMenuBackground, const Vector2f &pos);

    void draw(RenderTarget &window, const Vector2f &userCarPos) override;

    void drawEnd(RenderWindow &, const sf::Vector2f &, const std::string & , const Color& );

    void handleClick(const Vector2f &pos, vector<bool> &windows, size_t currWindow, bool *running) override;

    void handlePressHome(vector<bool> &, size_t);

    void handlePressMusic();

    void updateTextString(const TEXTS &, const unsigned &, const unsigned &) override;

private:
    void setPlayMenuTexts();

    Text createText(Vector2f, unsigned, const string &, Color) const;

    Sprite m_menuBackground;
    Sprite m_secondBackground;
    vector<Text> m_playMenuTexts;
    vector<string> Texts = {"Level: ", "$ "};
    unsigned m_coins = 0;
    bool m_music = true;
};
