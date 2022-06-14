#include "Controller.h"
#include "DebugDraw.h"

//____________________
Controller::Controller() : m_gui(m_gameWindow),
                           m_userMoved(false) {}

//___________________
void Controller::run() {
    DebugDraw d(m_gameWindow);          //DebugDraw;
    uint32 flags = b2Draw::e_shapeBit;
    d.SetFlags(flags);
    m_data.getWorld()->SetDebugDraw(&d);

    MyContactListener myContactListenerInstance; // Contact Listener

    while (m_gameWindow.isOpen() && m_running) {
        box2dStep(&myContactListenerInstance);
        handleEvents();
        handleData();
        handleReturnToMenu();
        draw();
    }
}

//__________________________
void Controller::handleData() {
    m_data.handlePlayerDead();
    m_data.removeObjects();
    m_data.setCarsPlace();
    if (m_data.raceFinished()) {
        // message end of level
        m_gui.setStartDrawMessage(!m_gui.getStartDrawMessage());
        m_data.setNextLevel(m_data.getIndexLevel() + 1);
    }
}

//___________________________________
void Controller::handleReturnToMenu() {
    if (m_gui.isWindowInOpenGameMenu() && m_userMoved) {
        m_data.setNextLevel(m_data.getIndexLevel());
        m_gui.setStartDrawMessage(true);
        m_userMoved = false;
    }
}

//__________________________________________________________
void Controller::box2dStep(MyContactListener *ContactListener) {
    m_data.setWorldStep();
    m_data.getWorld()->SetContactListener(ContactListener);
}

//____________________________
void Controller::handleEvents() {
    auto event = sf::Event();
    while (m_gameWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::MouseButtonPressed:
                m_gui.mouseEventPressed(m_gameWindow, event, m_running);
                break;
            case sf::Event::MouseMoved:
                m_gui.mouseEventMoved(m_gameWindow, event);
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
    if (m_userMoved && !m_gui.handlePauseButton(event.key.code))
        m_data.moveComputerCars(event);
}

//_____________________________________________________
void Controller::keyboardPressed(const sf::Event &event) {
    if (!m_gui.getStartDrawMessage() && !m_gui.handlePauseButton(event.key.code)) {
        m_data.moveUserCar(event);
        m_userMoved = true;
    }
}

//__________________________________________
void Controller::exitGame(const Event &event) {
    if ((event.key.code == sf::Keyboard::Escape && m_gui.isWindowInOpenGameMenu())
        || event.type == sf::Event::Closed)
        m_gameWindow.close();
}

//____________________
void Controller::draw() {
    m_gameWindow.clear();
    m_gui.drawWindow(m_gameWindow, m_data.getUserPosition());
    drawPlay();

    m_data.getWorld()->DebugDraw();
    m_gameWindow.display();
}

//________________________
void Controller::drawPlay() {
    if (m_gui.currWindowStatus(Play)) {
        m_data.drawData(m_gameWindow);
        m_gui.drawStartMessage(m_gameWindow);
    }
    else
        m_gui.setView(m_gameWindow, 1600.0f, 900.0f);
}