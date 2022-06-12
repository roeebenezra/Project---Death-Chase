#pragma once

#include "GameMenu.h"

class PauseButton : public Button {
public:
    PauseButton(unsigned TextureName, const Vector2f &pos, const IntRect &rect)
            : Button(TextureName, pos, rect) {}

    void draw(RenderTarget &window) override {
        window.draw(getSpriteButton());
    }

private:
    bool m_pauseGame = false;
};
