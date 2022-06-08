#include "IncMenus/MusicButton.h"

//___________________________________________________
MusicButton::MusicButton(unsigned TextureName, const Vector2f &pos, const IntRect &rect)
        : Button(TextureName, pos, rect) {
    setRects();
}

//_________________________
void MusicButton::setRects() {

}

//_________________________________________
void MusicButton::draw(RenderTarget &window) {
    window.draw(getSpriteButton());
}

//_______________________________
void MusicButton::setSpriteMusic() {
//    if (m_musicOn)
//        m_music.setTextureRect(IntRect(414, 0, 207, 207));
//    else
//        m_music.setTextureRect(IntRect(621, 0, 207, 207));
}

//_________________________________
void MusicButton::setSpriteclicks() {
//    if (m_clicksOn)
//        m_clicks.setTextureRect(IntRect(0, 0, 207, 207));
//    else
//        m_clicks.setTextureRect(IntRect(207, 0, 207, 207));
}