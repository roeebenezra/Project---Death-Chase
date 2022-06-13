#include "IncMenus/OpenMenuButton.h"

//____________________________________________________________________
OpenMenuButton::OpenMenuButton(unsigned TextureName, unsigned Name)
        : Button(TextureName, OpenMenuMenuButtonPos[Name], OpenMenuButtonsIntRect[Name]){}

//_____________________________________________
void OpenMenuButton::draw(RenderTarget &window) {
    if (isOnButton()) {
        getSpriteButton().setTextureRect(IntRect(getTextureRect().left, getTextureRect().top + MenuButtonHeight, MenuButtonWidth, MenuButtonHeight));
        window.draw(getSpriteButton());
    }
    else {
        getSpriteButton().setTextureRect(getTextureRect());
        window.draw(getSpriteButton());
    }
}

