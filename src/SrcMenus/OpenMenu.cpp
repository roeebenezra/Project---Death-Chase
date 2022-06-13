#include "IncMenus/OpenMenu.h"

OpenMenu::OpenMenu(unsigned Background, unsigned HowToPlay, Vector2f pos) : GameMenu(Background, pos),
                                            m_howToPlay(Resources::instance().getTexture(HowToPlay))
{
    m_howToPlay.setOrigin(m_howToPlay.getGlobalBounds().width / 2,
        m_howToPlay.getGlobalBounds().height / 2);

    m_howToPlay.setPosition(float(getSprite().getTexture()->getSize().x) / 2,
        float(getSprite().getTexture()->getSize().y) / 2);

    Resources::instance().playSoundMusic(MenuSound);
}

//________________________________________________________________
void OpenMenu::draw(RenderTarget& window, const Vector2f& userCarPos)
{
    window.draw(getSprite());
    for (size_t i = 0; i < getNumOfButtons(); ++i) {
        const auto& button = getButton(i);
        button->draw(window);
    }
    drawHowToPlay(window);
}

//______________________________________________
void OpenMenu::drawHowToPlay(RenderTarget& window) {
    if (m_pressHowToPlay)
        window.draw(m_howToPlay);
}

void OpenMenu::handleClick(const Vector2f& pos, vector<bool>& windows, size_t currWindow, bool* running)
{
    int press = int(mousePressButton(pos));
    if (press == PlayButton) {
        Resources::instance().stopSound();
        Resources::instance().setLoopSound(GameSound, true);
        windows[currWindow] = false;
        windows[Play] = true;
    }
    if (press == OptionsButton)
        setHowToPlay(true);
    else
        setHowToPlay(false);
    if (press == ExitButton)
        *(running) = false;
}