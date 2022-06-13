#pragma once

#include "GameMenu.h"

class PauseButton : public Button {
public:
    PauseButton(unsigned TextureName, unsigned name)
            : Button(TextureName, InGameMenuButtonPos[name], InGameButtonsIntRect[name]) {
    }

    void draw(RenderTarget &window) override {
        if (isOnButton()) {
            getSpriteButton().setTextureRect(IntRect(getTextureRect().left + InGameMenuButtonWidth, getTextureRect().top, InGameMenuButtonWidth, InGameMenuButtonHeight));
            window.draw(getSpriteButton());
        }
        else {
            getSpriteButton().setTextureRect(getTextureRect());
            window.draw(getSpriteButton());
        }
    }

private:
    Vector2f pos;
    bool m_pauseGame = false;
};
