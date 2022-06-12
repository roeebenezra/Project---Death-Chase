#pragma once

#include "GameMenu.h"


class PlayMenu : public GameMenu {
public:
    PlayMenu(unsigned TextureName, const Vector2f &pos)
            : GameMenu(TextureName, pos) {}

    void pauseGame() {

    }
};
