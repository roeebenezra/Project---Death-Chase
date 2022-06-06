#include "Controller.h"
#include "DebugDraw.h"

//____________________
Controller::Controller() : m_userMoved(false) {
    setMenus();
    setView();

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

//__________________
void Controller::run() {
    //DebugDraw
//    DebugDraw d(m_gameWindow);
//    uint32 flags = b2Draw::e_shapeBit;
//    d.SetFlags(flags);
//    m_data.getWorld()->SetDebugDraw(&d);

    // Contact Listener
    MyContactListener myContactListenerInstance;

    while (m_gameWindow.isOpen()) {
        DataSetup(&myContactListenerInstance);
        handleEvents();
        m_gameWindow.clear();
        if (m_windows[Play])
            setView();
        draw();
        m_gameWindow.display();
    }
}

//__________________________________________________________
void Controller::DataSetup(MyContactListener *ContactListener) {
    m_data.setWorldStep();
    m_data.getWorld()->SetContactListener(ContactListener);
}

//_______________________
void Controller::setView() {
    auto view = m_gameWindow.getView();
    view.setCenter(m_data.getUserPosition().x + 500, 1000);
    view.setSize(3300.0f, 2000.0f);
    if (m_windows[Play])
        m_gameWindow.setView(view);
}

//________________________
void Controller::setMenus() {
    m_image.setTexture(Resources::instance().getTexture(Background));
    Resources::instance().playSound(OpenSound);

    //open menu setup
    m_menus.emplace_back(make_unique<OpenMenu>(Resources::instance().getSprite(OpenMenuBackground), Vector2f(0, 0)));
    m_menus[OpenGameMenu]->add(make_unique<MusicButton>(Resources::instance().getSprite(musicIcons), Vector2f (900, 0)));

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
}

//___________________________________________________
void Controller::mouseEventPressed(const Event &event) {
    auto location = m_gameWindow.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
}

//____________________________________________________
void Controller::keyboardPressed(const sf::Event &event) {
    m_userMoved = true;
    if (m_data.getUserPosition().x < 40000 && m_data.getUserPosition().y - 200 > 0)
        m_data.moveUserCar(event);
}

//_________________________________________
void Controller::exitGame(const Event &event) {
    if (event.key.code == sf::Keyboard::Escape ||
        event.type == sf::Event::Closed)
        m_gameWindow.close();
}

//___________________
void Controller::draw() {
    if (m_windows[Play]) {
        m_gameWindow.draw(m_image);
        m_data.drawData(m_gameWindow);
    } else
        drawMenu();

    //    m_data.getWorld()->DebugDraw();
}

//__________________________
void Controller::drawMenu() {
    if (m_windows[OpenGameMenu])
        m_menus[OpenGameMenu]->draw(m_gameWindow);

    if (m_windows[HowToPlayMenu])
        m_menus[HowToPlayMenu]->draw(m_gameWindow);

    if (m_windows[ChooseCarMenu])
        m_menus[ChooseCarMenu]->draw(m_gameWindow);

    if (m_windows[InGameMenu])
        m_menus[InGameMenu]->draw(m_gameWindow);
}