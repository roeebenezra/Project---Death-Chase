#include "Controller.h"

//______________________
Controller::Controller()
        : m_view(Vector2f(0.0f, 0.0f), Vector2f(VIEW_HEIGHT, VIEW_WIDTH)),
          m_userMoved(false) {
    m_gameImage.setTexture(Resources::instance().getTexture(Background));
    m_gameImage.setScale(3, 1);
    auto view = m_gameWindow.getView();
    view.setCenter(m_data.getUserPosition().x + 500, 1000);
    m_gameWindow.setView(view);
}

//___________________
void Controller::run() {
    while (m_gameWindow.isOpen()) {
        handleEvents();
        m_gameWindow.clear();
        draw();
        m_gameWindow.display();
    }
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
    if (m_userMoved)
        m_data.moveComputerCars(event);
}

//_________________________________________________
void Controller::mouseEventMoved(const Event &event) {
    auto location = Vector2f(float(event.mouseMove.x), float(event.mouseMove.y));
}

//___________________________________________________
void Controller::mouseEventPressed(const Event &event) {
    auto location = m_gameWindow.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
}

//______________________________________________________
void Controller::keyboardPressed(const sf::Event &event) {
    m_userMoved = true;
    auto view = m_gameWindow.getView();
    if (m_data.getUserPosition().x < 40000 && m_data.getUserPosition().y - 200 > 0)
        m_data.moveUserCar(event);
    std::cout << m_data.getUserPosition().y << "\n";
    view.setCenter(m_data.getUserPosition().x + 500, 1000);
    m_gameWindow.setView(view);
}

//__________________________________________
void Controller::exitGame(const Event &event) {
    if (event.key.code == sf::Keyboard::Escape ||
        event.type == sf::Event::Closed)
        m_gameWindow.close();
}

//_____________________
void Controller::draw() {
    m_gameWindow.draw(m_gameImage);
    m_data.drawData(m_gameWindow);
}