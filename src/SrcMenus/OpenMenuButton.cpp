#include "IncMenus/OpenMenuButton.h"

//____________________________________________________________________
OpenMenuButton::OpenMenuButton(unsigned TextureName, const Vector2f& pos, const IntRect& rect)
        : Button(TextureName, pos, rect){}

//_____________________________________________
void OpenMenuButton::draw(RenderTarget &window) {
    if (isOnButton()) {
        getSpriteButton().setTextureRect(IntRect(0, getTextureRect().top + MenuButtonHeight, MenuButtonWidth, MenuButtonHeight));
        window.draw(getSpriteButton());
    }
    else {
        getSpriteButton().setTextureRect(getTextureRect());
        window.draw(getSpriteButton());
    }
}

