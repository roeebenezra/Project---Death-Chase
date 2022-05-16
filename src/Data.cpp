#include "Data.h"

//___________
Data::Data() {
    m_moving.push_back(FactoryObject::createObject<UserCar>(userCar));
    m_moving.push_back(FactoryObject::createObject<ComputerCar>(redCar));
    m_moving.push_back(FactoryObject::createObject<ComputerCar>(greenCar));
    m_static.push_back(FactoryObject::createObject<Ground>(ground_1));
    m_static.push_back(FactoryObject::createObject<Barrel>(barrel));
}

//_________________________________________
void Data::moveUserCar(const sf::Event &event) {
        m_moving[User]->move(event);
}
//_________________________________________
void Data::moveComputerCars(const sf::Event &event) {
    for (auto &moving: m_moving)
        if(moving != m_moving[User])
            moving->move(event);
}

//___________________________________________
void Data::drawData(sf::RenderWindow &window) {
    for (auto &moving: m_moving)
        moving->draw(window);

    for(auto &statics : m_static)
        statics->draw(window);
}
