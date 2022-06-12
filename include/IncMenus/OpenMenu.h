#pragma once

#include "GameMenu.h"

class OpenMenu : public GameMenu {
public:
    OpenMenu(unsigned Background, unsigned HowToPlay, Vector2f pos) : GameMenu(Background, pos),
            m_howToPlay(Resources::instance().getTexture(HowToPlay))
    {
        m_howToPlay.setOrigin(m_howToPlay.getGlobalBounds().width / 2,
                              m_howToPlay.getGlobalBounds().height / 2);

        m_howToPlay.setPosition(float(getSprite().getTexture()->getSize().x) / 2,
                                float(getSprite().getTexture()->getSize().y) / 2);

        Resources::instance().setLoopSound(OpenSound, true);
    }

    void draw(RenderTarget &window) override {
        window.draw(getSprite());
        for (size_t i = 0; i < getNumOfButtons(); ++i) {
            const auto &button = getButton(i);
            button->draw(window);
        }
        drawHowToPlay(window);
    }

    void drawHowToPlay(RenderTarget &window) {
        if (m_pressHowToPlay)
            window.draw(m_howToPlay);
    }

    void handleClick(const Vector2f &pos, vector<bool> &windows, size_t currWindow, bool *running) override {
        int press = int(mousePressButton(pos));
        if (press == PlayButton) {
            windows[currWindow] = false;
            windows[Play] = true;
        }
        if (press == OptionsButton)
            setHowToPlay(true);
        else
            setHowToPlay(false);
        if (press == ExitButton)
            *(running) = false;
    }

    void setHowToPlay(bool mode) { m_pressHowToPlay = mode; }

private:
//    vector<unique_ptr<Button>> m_buttons;
    Sprite m_howToPlay;
    bool m_pressHowToPlay = false;
};
