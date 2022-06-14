#include "Data.h"
#include <algorithm>

//__________
Data::Data() {
    setLevel();
}

//___________________
void Data::setLevel() {
    setWorld();
    m_map.getObjectsFromMapLevel(*this, m_indexLevel);
    m_floor.setFloor(m_world);
    m_boundaries.setBoundaries(m_world, {1200, 500});
    setCarsPlace();
}

//__________________
void Data::setWorld() {
    b2Vec2 gravity(0.0f, 10.f); //set gravity
    m_world = std::make_unique<b2World>(gravity);
}

//______________________
void Data::setWorldStep() {
    m_world->Step(m_timeStep, m_velocityIterations, m_positionIterations);
}

//__________________________________
void Data::setObject(std::string &name,
                     const sf::Vector2f &position,
                     const float rotation) {
    if (FactoryObject<CarObjects>::checkIfNameInMap(name)) {
        m_moving.push_back(FactoryObject<CarObjects>::create(m_world, name, position, rotation));
        return;
    }
    if (FactoryObject<StaticObject>::checkIfNameInMap(name)) {
        m_static.push_back(FactoryObject<StaticObject>::create(m_world, name, position, rotation));
        return;
    }
}

void Data::setCarsPlace() {
    int carPlace = carPLaceStart;
    std::vector<float> places;
    for (auto &moving: m_moving)
        places.push_back(moving->getPosition().x);

    std::sort(places.begin(), places.end());

    for (auto &place: places) {
        for (auto &moving: m_moving)
            if (moving->getPosition().x == place) {
                moving->setCarPlace(carPlace);
                carPlace--;
                break;
            }
    }
}

//____________________________________________
void Data::moveUserCar(const sf::Event &event) {
    if (!m_moving[User]->getCarAtFinishLine())
        m_moving[User]->move(event);
}

//_________________________________________________
void Data::moveComputerCars(const sf::Event &event) {
    for (auto &moving: m_moving)
        if (moving != m_moving[User] && !moving->getCarAtFinishLine())
            moving->move(event);
}

//____________________________
void Data::handlePlayerDead() {
    if (m_moving[User]->getObjectDead()) {
//        set position
        b2Vec2 checkPointPosition = m_map.getPlayerCheckPoint(m_indexLevel, m_moving[User]->getPosition().x);
        m_moving[User]->setPosition(checkPointPosition);
        m_moving[User]->setObjectDead(false);
        m_moving[User]->restartCar();
    }
}

//____________________________
bool Data::raceFinished()const {
    for (auto &moving: m_moving)
        if (!moving->getCarAtFinishLine())
            return false;
    return true;
}

//_________________________________________________
void Data::setNextLevel(const unsigned& levelIndex) {
    for (auto &moving: m_moving)
        moving->setObjectDead(true);
    for (auto &statics: m_static)
        statics->setObjectDead(true);
    removeObjects();
    m_indexLevel = levelIndex;
    setLevel();

}
//______________________
void Data::removeObjects() {
    for (auto &moving: m_moving)
        if (moving->getObjectDead())
            moving->destroyBody();

    std::erase_if(m_moving, [](auto &moving) { return moving->getObjectDead(); });

    for (auto &statics: m_static)
        if (statics->getObjectDead())
            statics->destroyBody();

    std::erase_if(m_static, [](auto &statics) { return statics->getObjectDead(); });
}

//____________________________________________________________________________
void Data::drawData(sf::RenderWindow &window) {

    setView(window, 3500.0f, 2000.0f);

    for (auto &moving: m_moving) {
        moving->updateObjects();
        moving->draw(window);
    }

    for (auto &statics: m_static) {
        statics->updateObjects();
        statics->draw(window);
    }
}

//__________________________________________
void Data::setView(sf::RenderWindow &window, float width, float height) const {
    auto view = window.getView();
    view.setCenter(getUserPosition().x + 500, 1000);
    view.setSize(width, height);
    window.setView(view);
}