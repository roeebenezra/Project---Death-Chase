#include "Controller.h"
#include "DebugDraw.h"

//____________________
Controller::Controller() : m_userMoved(false) {
    setMenus();
    setIcon();  //set window icon
}

//_______________________
void Controller::setIcon() {
    sf::Image iconTexture;
    iconTexture.loadFromFile(Textures[icon]);
    m_gameWindow.setIcon(iconTexture.getSize().x, iconTexture.getSize().y, iconTexture.getPixelsPtr());
}

//___________________
void Controller::run() {
    //DebugDraw
    DebugDraw d(m_gameWindow);
    uint32 flags = b2Draw::e_shapeBit;
    d.SetFlags(flags);
    m_data.getWorld()->SetDebugDraw(&d);

    MyContactListener myContactListenerInstance; // Contact Listener

    while (m_gameWindow.isOpen() && m_running) {
        box2dStep(&myContactListenerInstance);
        handleEvents();
        handleData();
        draw();
    }
}

//__________________________
void Controller::handleData() {
    m_data.removeObjects();
    m_data.setCarsPlace();
}

//__________________________________________________________
void Controller::box2dStep(MyContactListener *ContactListener) {
    m_data.setWorldStep();
    m_data.getWorld()->SetContactListener(ContactListener);
}

//________________________
void Controller::setMenus() {

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
    m_menus[Play]->add(make_unique<InGameMenuButton>(Buttons, InGameRestart));
}

//________________________
long Controller::CurrMenu() {
    return find(m_windows.begin(), m_windows.end(), true) - m_windows.begin();
}

//____________________________
void Controller::handleEvents() {
    auto event = sf::Event();
    while (m_gameWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::MouseButtonPressed:
                mouseEventPressed(event);
                break;
            case sf::Event::MouseMoved:
                mouseEventMoved(event);
                break;
            case sf::Event::KeyPressed:
                keyboardPressed(event);
                break;
            case sf::Event::Resized: {
                sf::FloatRect visibleArea(0, 0, float(event.size.width), float(event.size.height));
                m_gameWindow.setView(sf::View(visibleArea));
            }
                break;
            default:
                exitGame(event);
                break;
        }
    }
    if (m_userMoved && !m_menus.at(size_t(CurrMenu()))->isPause())
        m_data.moveComputerCars(event);
}

//_________________________________________________
void Controller::mouseEventMoved(const Event &event) {
    auto location = m_gameWindow.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
    m_menus.at(size_t(CurrMenu()))->isMouseOnButton(location);
}

//___________________________________________________
void Controller::mouseEventPressed(const Event &event) {
    auto location = m_gameWindow.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
    auto curr = CurrMenu();
    m_menus.at(size_t(curr))->handleClick(location, m_windows, size_t(curr), &m_running);
}

//_____________________________________________________
void Controller::keyboardPressed(const sf::Event &event) {
    if (/*!m_startMessageDraw.getDrawMessage() &&*/ !m_menus.at(size_t(CurrMenu()))->isPause()) {
        m_data.moveUserCar(event);
        m_userMoved = true;
    }
}

//__________________________________________
void Controller::exitGame(const Event &event) {
    if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
        m_gameWindow.close();
}

//____________________
void Controller::draw() {
    m_gameWindow.clear();
    m_menus.at(size_t(CurrMenu()))->draw(m_gameWindow, m_data.getUserPosition());
    drawPlay();
    m_data.getWorld()->DebugDraw();

    m_gameWindow.display();
}

//________________________
void Controller::drawPlay() {
    if (m_windows[Play]) {
        m_data.drawData(m_gameWindow);

        if (m_startMessageDraw.getDrawMessage())
            drawStartMessage();
    } else
        setView(1600.0f, 900.0f);
}

//________________________________________________
void Controller::setView(float width, float height) {
    auto view = m_gameWindow.getView();
    view.setCenter(width / 2, height / 2);
    view.setSize(width, height);
    m_gameWindow.setView(view);
}

//________________________________
void Controller::drawStartMessage() {
//    m_startMessageDraw.drawMessage(m_gameWindow);
}