#include "IncMenus/MusicButton.h"

//___________________________________________________
MusicButton::MusicButton(Sprite &sprite, Vector2f pos)
        : Button(sprite, pos), m_music(Vector2f(110, 148)), m_clicks(Vector2f(180, 148)) {
    setRects();
}

//_________________________
void MusicButton::setRects() {
    m_music.setTexture(&Resources::instance().getTexture(musicIcons));
    m_music.setTextureRect(IntRect(350, 0, 110, 148));
    m_music.setPosition(1480, 0);
    m_clicks.setTexture(&Resources::instance().getTexture(musicIcons));
    m_clicks.setTextureRect(IntRect(0, 0, 180, 148));
    m_clicks.setPosition(1330, 0);
}

//_________________________________________
void MusicButton::draw(RenderTarget &window) {
    window.draw(m_music);
    window.draw(m_clicks);
}

//_______________________________
void MusicButton::setSpriteMusic() {
    if (m_musicOn)
        m_music.setTextureRect(IntRect(414, 0, 207, 207));
    else
        m_music.setTextureRect(IntRect(621, 0, 207, 207));
}

//_________________________________
void MusicButton::setSpriteclicks() {
    if (m_clicksOn)
        m_clicks.setTextureRect(IntRect(0, 0, 207, 207));
    else
        m_clicks.setTextureRect(IntRect(207, 0, 207, 207));
}