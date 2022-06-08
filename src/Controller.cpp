#include "Controller.h"
#include "DebugDraw.h"

//____________________
Controller::Controller() {
    m_gameImage.setTexture(Resources::instance().getTexture(Background));
    m_gameImage.setScale(3,1);
//    m_gameWindow.setFramerateLimit(80);
    setView();
    setIcon();
}

//_________________________
void Controller::setIcon() {
    sf::Image iconTexture;
    iconTexture.loadFromFile(NAMES[icon]);
    m_gameWindow.setIcon(iconTexture.getSize().x, iconTexture.getSize().y, iconTexture.getPixelsPtr());
}

//_________________________
void Controller::setView() {
    auto view = m_gameWindow.getView();
    view.setCenter(m_data.getUserPosition().x + 500, 1000);
    m_gameWindow.setView(view);
}

//__________________
void Controller::run() {
    //DebugDraw.h
    DebugDraw d(m_gameWindow);
    uint32 flags = b2Draw::e_shapeBit;
    d.SetFlags(flags);
    m_data.getWorld()->SetDebugDraw(&d);

    MyContactListener myContactListenerInstance;

    while (m_gameWindow.isOpen()) {
        m_data.setWorldStep();
        m_data.getWorld()->SetContactListener(&myContactListenerInstance);
        handleEvents();
        m_data.removeObjects();
        m_data.setCarsPlace();
        m_gameWindow.clear();
        setView();
        draw();
        m_gameWindow.display();
    }
}

//___________________________
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
}

//___________________________________________________
void Controller::mouseEventPressed(const Event &event) {
    auto location = m_gameWindow.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
}

//____________________________________________________
void Controller::keyboardPressed(const sf::Event &event) {
    if (m_data.getUserPosition().x < 40000 && m_data.getUserPosition().y - 200 > 0) {
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

//______________________
void Controller::draw() {
    m_gameWindow.draw(m_gameImage);
    m_data.drawData(m_gameWindow);
//    m_gameWindow.setFramerateLimit(6);
//    Sprite s;
//    s.setTexture(Resources::instance().getTexture(finishLine));
//    s.setPosition({3500, 500});
//    s.setScale(2,2);
//    m_gameWindow.draw(s);
//    m_data.getWorld()->DebugDraw();
}