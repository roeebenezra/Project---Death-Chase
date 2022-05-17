#include "Data.h"

//__________
Data::Data() : m_map(std::cin) {
    m_map.readMapFile(*this);
}

//______________________________________
void Data::setObject(std::string &name,
                     const sf::Vector2f &position,
                     const sf::Vector2f &scale) {
    FactoryObject<MovingObject> m;
    if (m.checkIfNameInMap(name)) {
        m_moving.push_back(FactoryObject<MovingObject>::create(name, position, scale));
        return;
    }
    FactoryObject<StaticObject> s;
    if (s.checkIfNameInMap(name)) {
        m_static.push_back(FactoryObject<StaticObject>::create(name, position, scale));
        return;
    }
}

//____________________________________________
void Data::moveUserCar(const sf::Event &event) {
    m_moving[User]->move(event);
}

//_________________________________________________
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