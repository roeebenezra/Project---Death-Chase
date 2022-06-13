#pragma once

#include "GameMenu.h"

class OpenMenuButton : public Button {
public:
    OpenMenuButton(unsigned TextureName, unsigned Name);

    void draw(RenderTarget&) override;

private:
    IntRect m_rect;
};