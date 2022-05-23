#include "Controller.h"

//____________________
Controller::Controller()
    m_gameImage.setTexture(Resources::instance().getTexture(Background));
    m_gameImage.setScale(3, 1);
    auto view = m_gameWindow.getView();
    view.setCenter(m_data.getUserPosition().x + 500, 1000);
    m_gameWindow.setView(view);
//    const auto viewSize = sf::Vector2f(m_gameWindow.getSize().x, m_gameWindow.getSize().y);
//    m_views.emplace_back(sf::Vector2f{0, 0}, viewSize);
//    m_views.back().setViewport({0.f, 0.f, 1.f, 1.f});
//    m_views.back().setCenter(m_data.getUserPosition().x + 500, 1000);
//
//    m_views.emplace_back(sf::Vector2f{0, 0}, sf::Vector2f(100, 100));
//    m_views.back().setCenter(m_data.getUserPosition().x + 500, 1000);
//    m_views.back().setViewport({0.f, 0.8f, 0.2f, 0.2f});

//    const auto viewSize = sf::Vector2f(m_gameWindow.getSize().x / 2.f, m_gameWindow.getSize().y * 1.f);
//    m_views.emplace_back(sf::Vector2f{ 0,0 }, viewSize);
//    m_views.back().setViewport({ 0.f, 0.f, 0.5f, 1.f });
//    auto viewCenter = m_views.back().getCenter();
//    viewCenter.x += viewSize.x;
//    m_views.emplace_back(viewCenter, viewSize);
//    m_views.back().setViewport({ 0.5f, 0.f, 0.5f, 1.f });
}

//___________________
void Controller::run() 
{
    while (m_gameWindow.isOpen()) 
    {
        m_data.setWorldStep();
        handleEvents();
        m_gameWindow.clear();
        draw();
        m_gameWindow.display();
    }
}

//____________________________
void Controller::handleEvents() 
{
    auto event = sf::Event();
    while (m_gameWindow.pollEvent(event))
    {
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
void Controller::mouseEventMoved(const Event &event) 
{
    auto location = Vector2f(float(event.mouseMove.x), float(event.mouseMove.y));
}

//___________________________________________________
void Controller::mouseEventPressed(const Event &event) {
    auto location = m_gameWindow.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
}

//____________________________________________________
void Controller::keyboardPressed(const sf::Event &event) 
{
    m_userMoved = true;
    auto view = m_gameWindow.getView();
    if (m_data.getUserPosition().x < 40000 && m_data.getUserPosition().y - 200 > 0)
        m_data.moveUserCar(event);
    view.setCenter(m_data.getUserPosition().x + 500, 1000);
    m_gameWindow.setView(view);
//    for (auto &view: m_views)
//        view.setCenter(m_data.getUserPosition().x + 500, m_data.getUserPosition().y - 500);
}

//__________________________________________
void Controller::exitGame(const Event &event) 
{
    if (event.key.code == sf::Keyboard::Escape ||
        event.type == sf::Event::Closed)
        m_gameWindow.close();
}
//_____________________
void Controller::draw() {
    for (const auto &view: m_views) {
        m_gameWindow.setView(view);
        break;
    }
    m_gameWindow.draw(m_gameImage);
    m_data.drawData(m_gameWindow);
}