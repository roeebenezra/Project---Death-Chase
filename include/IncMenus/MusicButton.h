#pragma once

#include "GameMenu.h"

class MusicButton : public Button {
public:
    MusicButton(Sprite &sprite, Vector2f pos);

    void setRects();

    void draw(RenderTarget &window) override;

    void setSpriteMusic();

    void setSpriteclicks();

private:
    RectangleShape m_music;
    RectangleShape m_clicks;

    bool m_musicOn = true;
    bool m_clicksOn = true;
};

