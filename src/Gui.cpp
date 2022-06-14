#include "Gui.h"

//_________________________________
Gui::Gui(sf::RenderWindow &window) {
    setMenus();
    setIcon(window);  // set game application icon
}

//__________________________________________
void Gui::setIcon(sf::RenderWindow &window) {
    sf::Image iconTexture;
    iconTexture.loadFromFile(Textures[icon]);
    window.setIcon(iconTexture.getSize().x, iconTexture.getSize().y, iconTexture.getPixelsPtr());
}

//__________________
void Gui::setMenus() {

    m_menus.emplace_back(make_unique<OpenMenu>(OpenMenuBackground, HowToPlay, Vector2f(0, 0))); //Open Menu setup

    m_menus[OpenGameMenu]->add(make_unique<OpenMenuButton>(Buttons, OpenMenuPlay));
    m_menus[OpenGameMenu]->add(make_unique<OpenMenuButton>(Buttons, OpenMenuOptions));
    m_menus[OpenGameMenu]->add(make_unique<OpenMenuButton>(Buttons, OpenMenuExit));

    m_menus[OpenGameMenu]->add(make_unique<MusicButton>(musicIcons, Vector2f(1350, 0), SoundButtonRect));
    m_menus[OpenGameMenu]->add(make_unique<MusicButton>(musicIcons, Vector2f(1480, 0), SoundButtonRect2));

    //In Game Menu setup
    m_menus.emplace_back(make_unique<PlayMenu>(PlayBackground, InGameMenuBackground, Vector2f(0, 0)));

    m_menus[Play]->add(make_unique<PauseButton>(Buttons, InGamePause)); //add Pause

    m_menus[Play]->add(make_unique<InGameMenuButton>(Buttons, InGameMusic));
    m_menus[Play]->add(make_unique<InGameMenuButton>(Buttons, InGameHome));
    m_menus[Play]->add(make_unique<InGameMenuButton>(Buttons, InGamePlay));
}

//__________________
long Gui::CurrMenu() {
    return find(m_windows.begin(), m_windows.end(), true) - m_windows.begin();
}

//_________________________________________
void Gui::setView(sf::RenderWindow &window,
                  float width,
                  float height) {
    auto view = window.getView();
    view.setCenter(width / 2, height / 2);
    view.setSize(width, height);
    window.setView(view);
}

//____________________________________________
void Gui::mouseEventMoved(const Event &event) {
    auto location = Vector2f(float(event.mouseMove.x), float(event.mouseMove.y));
    m_menus.at(size_t(CurrMenu()))->isMouseOnButton(location);
}

//___________________________________________________
void Gui::mouseEventPressed(sf::RenderWindow &window,
                            const Event &event,
                            bool &running) {
    auto location = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
    auto curr = CurrMenu();
    m_menus.at(size_t(curr))->handleClick(location, m_windows, size_t(curr), &running);
}

//_______________________________________________________
bool Gui::handlePauseButton(const sf::Keyboard::Key &key) {
    if (key == sf::Keyboard::Escape)
        m_menus.at(size_t(CurrMenu()))->setPause(!m_menus.at(size_t(CurrMenu()))->isPause());
    return m_menus.at(size_t(CurrMenu()))->isPause();
}

//_____________________________________________
void Gui::drawWindow(sf::RenderWindow &window,
                     const sf::Vector2f &playerPosition) {
    m_menus.at(size_t(CurrMenu()))->draw(window, playerPosition);
}

//__________________________________________________
void Gui::drawStartMessage(sf::RenderWindow &window) {
    if (m_startMessageDraw.getDrawMessage())
        m_startMessageDraw.drawMessage(window);
}