#pragma once

#include "GameMenu.h"

class PauseButton : public Button {
public:
    PauseButton(unsigned TextureName, unsigned name);

    void draw(RenderTarget& window) override;

private:
    Vector2f pos;
    bool m_pauseGame = false;
};
