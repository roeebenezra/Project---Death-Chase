#pragma once

#include "GameMenu.h"

class OpenMenuButton : public Button {
public:
    OpenMenuButton(unsigned TextureName, const Vector2f &, const IntRect &);

    void draw(RenderTarget&) override;

private:
    IntRect m_rect;
};