#include "Data.h"

//__________
Data::Data() : m_map(std::cin) {
    m_map.readMapFile(*this);
//    m_moving.push_back(FactoryObject<MovingObject>::create("userCar"));
//    m_moving.push_back(FactoryObject<MovingObject>::create("redCar"));
//    m_moving.push_back(FactoryObject<MovingObject>::create("greenCar"));
//    m_static.push_back(FactoryObject<StaticObject>::create("barrel"));
//    m_static.push_back(FactoryObject<StaticObject>::create("ground_1"));
//    m_static.push_back(FactoryObject<StaticObject>::create("ground_2"));
//    m_static.push_back(FactoryObject<StaticObject>::create("ground_3"));
//    m_static.push_back(FactoryObject<StaticObject>::create("ground_4"));
//    m_static.push_back(FactoryObject<StaticObject>::create("ground_5"));
//    m_static.push_back(FactoryObject<StaticObject>::create("ground_6"));
//    m_static.push_back(FactoryObject<StaticObject>::create("ground_7"));
//    m_static.push_back(FactoryObject<StaticObject>::create("ground_8"));
//    m_static.push_back(FactoryObject<StaticObject>::create("ground_9"));
}

//________________________________________
void Data::setObject(std::string &name) {
    FactoryObject<MovingObject> m;
    if(m.checkIfNameInMap(name))
        m_moving.push_back(FactoryObject<MovingObject>::create(name));

    FactoryObject<StaticObject> s;
    if(s.checkIfNameInMap(name))
        m_static.push_back(FactoryObject<StaticObject>::create(name));

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