#pragma once

#include "GameMenu.h"
#include "Data.h"

class Data;

class PlayMenu : public GameMenu {
public:
    PlayMenu(unsigned playBackground, unsigned InGameMenuBackground, const Vector2f &pos)
            : GameMenu(playBackground, pos), m_menuBackground(Resources::instance().getTexture(InGameMenuBackground)) {
        m_menuBackground.setOrigin(m_menuBackground.getLocalBounds().width / 2,
                                   m_menuBackground.getLocalBounds().height / 2);
    }

    void draw(RenderTarget &window, const Vector2f& userCarPos) override {
        window.draw(getSprite());
        window.draw(m_buttons.at(InGamePause)->getSpriteButton());
        if (m_pressPause) {
            m_menuBackground.setPosition(userCarPos.x+320 ,userCarPos.y-1050);
            window.draw(m_menuBackground);
            for (auto &button: m_buttons) {
                button->draw(window);
            }
        }
    }

    void handleClick(const Vector2f &pos, vector<bool> &windows, size_t currWindow, bool *running) override {
        int press = int(mousePressButton(pos)) - 1;
        if (press == InGamePause)
            m_pressPause = true;
        if (press == InGamePlay)
            m_pressPause = false;
        if (press == InGameHome) {
            windows[currWindow] = false;
            windows[OpenGameMenu] = true;
        }
        if (press == InGameMusic) {
            if(m_music){
                m_music = false;
                getButton(InGameMusic)->setClickOnButton(true);
                Resources::instance().stopSound(GameSound);
            }
            else {
                m_music = true;
                getButton(InGameMusic)->setClickOnButton(false);
                Resources::instance().setLoopSound(GameSound, true);
            }
        }
    }

    void pauseGame() {}

private:
    Sprite m_menuBackground;
    bool m_pressPause = false;
    bool m_music = true;
};
