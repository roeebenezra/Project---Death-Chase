#pragma once

#include "GameMenu.h"

class MusicButton : public Button {
public:
    MusicButton(unsigned TextureName, const Vector2f &, const IntRect &);

    void draw(RenderTarget &window) override;

    bool isMousePressOnButton(const Vector2f& pos) override;
};

