#include "Data.h"

//__________
Data::Data()
{
    setWorld();
    m_map.readMapFile(*this);
}

//__________________
void Data::setWorld() 
{
    //set gravity
    b2Vec2 gravity(0.0f, 10.f);
    m_world = std::make_unique<b2World>(gravity);

//    Make the ground
//    b2BodyDef groundBodyDef;
//    groundBodyDef.position.Set(200, 1600);
//
//    set ground in world
//    m_groundBody = m_world->CreateBody(&groundBodyDef);
//
//    Make the ground fixture
//    b2PolygonShape groundBox;
//    groundBox.SetAsBox(20000, 10);
//    auto fixture = m_groundBody->CreateFixture(&groundBox, 0.0f);
//    fixture->SetDensity(10.f);
//    fixture->SetFriction(10.f);
}

//______________________
void Data:: setWorldStep() 
{
    m_world->Step(m_timeStep, m_velocityIterations, m_positionIterations);
}

//__________________________________
void Data::setObject(std::string &name,
                     const sf::Vector2f &position,
                     const sf::Vector2f &scale) {
    if (FactoryObject<MovingObject>::checkIfNameInMap(name)) {
        m_moving.push_back(FactoryObject<MovingObject>::create(m_world, name, position, scale));
        return;
    }
    if (FactoryObject<StaticObject>::checkIfNameInMap(name)) {
        m_static.push_back(FactoryObject<StaticObject>::create(m_world, name, position, scale));
        return;
    }
}

//____________________________________________
void Data::moveUserCar(const sf::Event &event) {
    m_moving[User]->move(event);
}

//_________________________________________________
void Data::moveComputerCars(const sf::Event &event)
{
    for (auto &moving: m_moving)
        if (moving != m_moving[User])
            moving->move(event);
}

//___________________________________________
void Data::drawData(sf::RenderWindow &window) 
{
    for (auto &moving: m_moving)
        moving->draw(window);

    for (auto &statics: m_static)
        statics->draw(window);
}