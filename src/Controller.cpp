#include "Controller.h"
#include "DebugDraw.h"

//____________________
Controller::Controller()
        : m_userMoved(false) {
//    Resources::instance().playInLoopSound(OpenSound);
    setMenus();
    setIcon();
}

//_________________________
void Controller::setIcon() {
    sf::Image iconTexture;
    iconTexture.loadFromFile(Textures[icon]);
    m_gameWindow.setIcon(iconTexture.getSize().x, iconTexture.getSize().y, iconTexture.getPixelsPtr());
}

//____________________
void Controller::run() {

    DebugDraw d(m_gameWindow); //DebugDraw
    uint32 flags = b2Draw::e_shapeBit;
    d.SetFlags(flags);
    m_data.getWorld()->SetDebugDraw(&d);

    MyContactListener myContactListenerInstance; // Contact Listener

    while (m_gameWindow.isOpen()) {
        box2dStep(&myContactListenerInstance);
        handleEvents();
        handleData();
        draw();
    }
}

//__________________________________________________________
void Controller::box2dStep(MyContactListener *ContactListener) {
    m_data.setWorldStep();
    m_data.getWorld()->SetContactListener(ContactListener);
}

//________________________
void Controller::setMenus() {
    //Open Menu setup
    IntRect OpenMenuRect(0, 0, MenuButtonWidth, MenuButtonHeight);
    IntRect SoundButtonRect(0, 0, clicksButtonWidth, SoundButtonHeight);
    IntRect SoundButtonRect2(320, 0, MusicButtonWidth, SoundButtonHeight);
    IntRect PauseButtonRect(0, 0, 122, 122);

    Vector2f OpenMenuButtonPos = {1100, 300};

    m_menus.emplace_back(make_unique<OpenMenu>(OpenMenuBackground, Vector2f(0, 0)));
    m_menus[OpenGameMenu]->add(make_unique<MusicButton>(musicIcons, Vector2f(1350, 0), SoundButtonRect));
    m_menus[OpenGameMenu]->add(make_unique<MusicButton>(musicIcons, Vector2f(1480, 0), SoundButtonRect2));

    for (int i = 0; i < 3; ++i) {
        m_menus[OpenGameMenu]->add(make_unique<OpenMenuButton>(OpenMenuButtons, OpenMenuButtonPos, OpenMenuRect));
        OpenMenuButtonPos.y += 150;
        OpenMenuRect.top += MenuButtonHeight * 2;
    }
//    m_menus[OpenGameMenu]->add(make_unique<OpenMenuButton>(pos, Rect));
//    m_menus[OpenGameMenu]->add(make_unique<OpenMenuButton>(pos, Rect));

    //In Game Menu setup
    m_menus.emplace_back(make_unique<PlayMenu>(PlayBackground, Vector2f(0, 0)));
    m_menus[Play]->add(make_unique<PauseButton>(Buttons, Vector2f{0, 0}, PauseButtonRect));
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
            default:
                exitGame(event);
                break;
        }
    }
//    if (m_userMoved)
//        m_data.moveComputerCars(event);
}

//_________________________________________________
void Controller::mouseEventMoved(const Event &event) {
    auto location = Vector2f(float(event.mouseMove.x), float(event.mouseMove.y));
    m_menus.at(size_t(CurrMenu()))->isMouseOnButton(location);
}

//___________________________________________________
void Controller::mouseEventPressed(const Event &event) {
    auto location = m_gameWindow.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
    if (m_menus.at(size_t(CurrMenu()))->isMousePressOnButton(location)) {
        m_windows[size_t(CurrMenu())] = false;
        m_windows[Play] = true;
    }
}

//____________________________________________________
void Controller::keyboardPressed(const sf::Event &event) {
    if (!m_startMessageDraw.getDrawMessage()) {
        m_data.moveUserCar(event);
        m_userMoved = true;
    }
}

//___________________________________________
void Controller::exitGame(const Event &event) {
    if (event.key.code == sf::Keyboard::Escape ||
        event.type == sf::Event::Closed)
        m_gameWindow.close();
}

//___________________________
void Controller::handleData() {
    m_data.removeObjects();
    m_data.setCarsPlace();
}

//____________________
void Controller::draw() {
    m_gameWindow.clear();
    m_menus.at(size_t(CurrMenu()))->draw(m_gameWindow); // draw background
    drawPlay();
//    m_data.getWorld()->DebugDraw();
    m_gameWindow.display();
}

void Controller::drawPlay() {
    if (m_windows[Play]) {
        m_data.drawData(m_gameWindow, m_menus[size_t(CurrMenu())]); // draw game objects

        if (m_startMessageDraw.getDrawMessage())
            drawStartMessage();
    }
}

void Controller::drawStartMessage() {
    m_startMessageDraw.drawMessage(m_gameWindow);
}
