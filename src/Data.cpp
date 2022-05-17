#include "Data.h"

//___________
Data::Data() {
    m_moving.push_back(FactoryObject<MovingObject>::create("userCar"));
    m_moving.push_back(FactoryObject<MovingObject>::create("redCar"));
    m_moving.push_back(FactoryObject<MovingObject>::create("greenCar"));
    m_static.push_back(FactoryObject<StaticObject>::create("barrel"));
    m_static.push_back(FactoryObject<StaticObject>::create("ground_1"));
}

//_________________________________________
void Data::moveUserCar(const sf::Event &event) {
    m_moving[User]->move(event);
}

//_________________________________________
void Data::moveComputerCars(const sf::Event &event) {
    for (auto &moving: m_moving)
        if (moving != m_moving[User])
            moving->move(event);
}

//___________________________________________
void Data::drawData(sf::RenderWindow &window) {
    for (auto &moving: m_moving)
        moving->draw(window);

    for (auto &statics: m_static)
        statics->draw(window);
}
