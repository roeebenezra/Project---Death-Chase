#pragma once

#include "GameMenu.h"

class MusicButton : public Button {
public:
    MusicButton(unsigned TextureName, const Vector2f &, const IntRect &);

    void setRects();

    void draw(RenderTarget &window) override;

    void setSpriteMusic();

    void setSpriteclicks();

private:
    bool m_musicOn = true;
    bool m_clicksOn = true;
};

