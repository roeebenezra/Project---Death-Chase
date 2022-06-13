#include "IncMenus/MusicButton.h"

//____________________________________________________________________________________
MusicButton::MusicButton(unsigned TextureName, const Vector2f &pos, const IntRect &rect)
        : Button(TextureName, pos, rect) {}

//_________________________________________
void MusicButton::draw(RenderTarget &window) {
    if (isClickOnButton()) {
        getSpriteButton().setTextureRect(
                IntRect(getTextureRect().left + getTextureRect().width, 0, getTextureRect().width,
                        getTextureRect().height));
        window.draw(getSpriteButton());
    } else {
        getSpriteButton().setTextureRect(getTextureRect());
        window.draw(getSpriteButton());
    }
}

//________________________________________________________
bool MusicButton::isMousePressOnButton(const Vector2f &pos) {
    if (getSpriteButton().getGlobalBounds().contains(pos)) {
        if (isClickOnButton()) {
            setClickOnButton(false);
            Resources::instance().setLoopSound(MenuSound, true);
        }
        else {
            setClickOnButton(true);
            Resources::instance().setLoopSound(MenuSound, false);
        }
        return true;
    }
    return false;
}