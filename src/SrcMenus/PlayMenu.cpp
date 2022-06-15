#include "IncMenus/PlayMenu.h"

//___________________________________________________________________________________________
PlayMenu::PlayMenu(unsigned playBackground, unsigned InGameMenuBackground, const Vector2f &pos)
        : GameMenu(playBackground, pos), m_menuBackground(Resources::instance().getTexture(InGameMenuBackground)),
          m_secondBackground(Resources::instance().getTexture(PlayBackground2)) {
    m_menuBackground.setOrigin(m_menuBackground.getLocalBounds().width / 2,
                               m_menuBackground.getLocalBounds().height / 2);
    m_secondBackground.setPosition({16500, 300});
    m_secondBackground.setOrigin(m_menuBackground.getLocalBounds().width / 2,
                                 m_menuBackground.getLocalBounds().height / 2);
    setPlayMenuTexts();
}

//________________________________
void PlayMenu::setPlayMenuTexts() {
    sf::Vector2f position;
    for (auto &i: Texts) {
        Text text = createText(position, FontSize, i, Color::Black);
        m_playMenuTexts.push_back(text);
    }
    Texts[LEVEL] += std::to_string(1);
    m_playMenuTexts[LEVEL].setString(Texts[LEVEL]);
    Texts[COINS] += std::to_string(m_coins);
    m_playMenuTexts[COINS].setString(Texts[COINS]);
}

//_____________________________________________________
Text PlayMenu::createText(Vector2f pos, unsigned size,
                          const string &name, Color color) const {
    Text text(name, Resources::instance().getFontForText(), size);
    text.setFillColor(color);
    text.setPosition(pos);

    return text;
}

//______________________________________________
void PlayMenu::updateTextString(const TEXTS &text,
                                const unsigned &num,
                                const unsigned &index) {
    Texts[text].replace(index, std::to_string(num).size() + 1, std::to_string(num));
    m_playMenuTexts[text].setString(Texts[text]);
}

//_________________________________________________________________
void PlayMenu::draw(RenderTarget &window, const Vector2f &userCarPos) {
    window.draw(getSprite());
    window.draw(m_secondBackground);
    window.draw(m_buttons.at(InGamePause)->getSpriteButton());
    m_buttons.at(InGamePause)->getSpriteButton().setPosition(userCarPos.x + 2000, 50);
    if (m_pressPause) {
        m_menuBackground.setPosition(userCarPos.x + 320, 800);      //update Menu Position
        m_buttons.at(InGameMusic)->getSpriteButton().setPosition(userCarPos.x + 100, 850);
        m_buttons.at(InGameHome)->getSpriteButton().setPosition(userCarPos.x + 250, 700);
        m_buttons.at(InGamePlay)->getSpriteButton().setPosition(userCarPos.x + 400, 850);
        m_buttons.at(InGameRestart)->getSpriteButton().setPosition(userCarPos.x + 250, 850);
        window.draw(m_menuBackground);
        for (auto &button: m_buttons)
            button->draw(window);
    }

    for (unsigned i = 0; i < m_playMenuTexts.size(); i++) {
        m_playMenuTexts[i].setPosition({userCarPos.x + PlayMenuTextPositions[i].x, PlayMenuTextPositions[i].y});
        window.draw(m_playMenuTexts[i]);
    }
}

//____________________________________________
void PlayMenu::drawEnd(RenderWindow & window,
                       const sf::Vector2f &position,
                       const std::string & message,
                     const Color& color)
{
    Text text = createText({position.x + 200, position.y - 1000}, 250, message, color);
    text.setString(message);
    Clock clock;
    while (clock.getElapsedTime().asSeconds() < 2) {
        window.draw(text);
        window.display();
    }
}

//___________________________________________________________________________________________________
void PlayMenu::handleClick(const Vector2f &pos, vector<bool> &windows, size_t currWindow, bool *running) {
    int press = int(mousePressButton(pos)) - 1;

    getButton(InGameHome)->setClickOnButton(false);
    getButton(InGamePlay)->setClickOnButton(false);
    getButton(InGameRestart)->setClickOnButton(false);

    if (press == InGamePause)
        setPause(!m_pressPause);

    if (press == InGamePlay)
        m_pressPause = false;

    if (press == InGameHome)
        handlePressHome(windows, currWindow);

    if (press == InGameMusic)
        handlePressMusic();

    if (press == InGameRestart){
        setRestart(!m_pressRestart);
    }
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