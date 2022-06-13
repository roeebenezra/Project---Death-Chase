#pragma once

#include "GameMenu.h"

class InGameMenuButton : public Button {
public:
    InGameMenuButton(unsigned TextureName, unsigned name) : Button(TextureName, InGameMenuButtonPos[name], InGameButtonsIntRect[name]) {}

    void draw(RenderTarget& window) override {
        if (isClickOnButton()) {
            getSpriteButton().setTextureRect(IntRect(getTextureRect().left + InGameMenuButtonWidth , getTextureRect().top, InGameMenuButtonWidth, InGameMenuButtonHeight));
            window.draw(getSpriteButton());
        }
        else {
            getSpriteButton().setTextureRect(getTextureRect());
            window.draw(getSpriteButton());
        }
    }

private:
    IntRect m_rect;
};