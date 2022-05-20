#include "Data.h"

//__________
Data::Data() : m_map() {
    m_map.readMapFile(*this);
    setWorld();
    for (auto &moving: m_moving)
        moving->setB2d(m_world);

    for (auto &statics: m_static)
        statics->setB2d(m_world);
}

//__________________
void Data::setWorld() {
    b2Vec2 gravity(0.0f, 10.0f);
    auto world = std::make_unique<b2World>(gravity);
    m_world = std::move(world);
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, 0.0f);
    m_groundBody = m_world->CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(1000.0f, 1000.0f);
    m_groundBody->CreateFixture(&groundBox, 0.0f);
}

//________________________
void Data:: setWorldStep() {
    m_world->Step(m_timeStep, m_velocityIterations, m_positionIterations);
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