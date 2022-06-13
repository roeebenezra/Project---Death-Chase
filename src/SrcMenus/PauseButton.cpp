#include "IncMenus/PauseButton.h"

PauseButton::PauseButton(unsigned TextureName, unsigned name)
    : Button(TextureName, InGameMenuButtonPos[name], InGameButtonsIntRect[name]) {
}

void PauseButton::draw(RenderTarget& window)
{
    if (isOnButton()) {
        getSpriteButton().setTextureRect(IntRect(getTextureRect().left + InGameMenuButtonWidth, getTextureRect().top, InGameMenuButtonWidth, InGameMenuButtonHeight));
        window.draw(getSpriteButton());
    }
    else {
        getSpriteButton().setTextureRect(getTextureRect());
        window.draw(getSpriteButton());
    }
}