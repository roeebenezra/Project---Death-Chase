#include "IncMenus/PlayMenu.h"

//___________________________________________________________________________________________
PlayMenu::PlayMenu(unsigned playBackground, unsigned InGameMenuBackground, const Vector2f &pos)
        : GameMenu(playBackground, pos), m_menuBackground(Resources::instance().getTexture(InGameMenuBackground)) {
    m_menuBackground.setOrigin(m_menuBackground.getLocalBounds().width / 2,
                               m_menuBackground.getLocalBounds().height / 2);
}

//_________________________________________________________________
void PlayMenu::draw(RenderTarget &window, const Vector2f &userCarPos) {
    window.draw(getSprite());
    window.draw(m_buttons.at(InGamePause)->getSpriteButton());
    m_buttons.at(InGamePause)->getSpriteButton().setPosition(userCarPos.x + 2000, 50);
    if (m_pressPause)
    {
        m_menuBackground.setPosition(userCarPos.x + 320, 800);      //update Menu Position
        m_buttons.at(InGameMusic)->getSpriteButton().setPosition(userCarPos.x + 100, 800);
        m_buttons.at(InGameHome)->getSpriteButton().setPosition(userCarPos.x + 250, 800);
        m_buttons.at(InGamePlay)->getSpriteButton().setPosition(userCarPos.x + 400, 800);
        window.draw(m_menuBackground);
        for (auto &button: m_buttons)
            button->draw(window);
    }
}

//___________________________________________________________________________________________________
void PlayMenu::handleClick(const Vector2f &pos, vector<bool> &windows, size_t currWindow, bool *running) {
    int press = int(mousePressButton(pos)) - 1;

    if (press == InGamePause)
        handlePressPause();

    if (press == InGamePlay)
        m_pressPause = false;

    if (press == InGameHome)
        handlePressHome(windows, currWindow);

    if (press == InGameMusic)
        handlePressMusic();
}

//______________________________
void PlayMenu::handlePressPause() {
    getButton(InGameHome)->setClickOnButton(false);
    getButton(InGamePlay)->setClickOnButton(false);
    m_pressPause = true;
}

//_____________________________________________________________________
void PlayMenu::handlePressHome(vector<bool> &windows, size_t currWindow) {
    windows[currWindow] = false;
    windows[OpenGameMenu] = true;
    setPause(false);
    Resources::instance().playSoundMusic(MenuSound);
}

//______________________________
void PlayMenu::handlePressMusic() {
    if (m_music) {
        m_music = false;
        getButton(InGameMusic)->setClickOnButton(true);
        Resources::instance().stopSound();
    } else {
        m_music = true;
        getButton(InGameMusic)->setClickOnButton(false);
        Resources::instance().setLoopSound(GameSound, true);
    }
}