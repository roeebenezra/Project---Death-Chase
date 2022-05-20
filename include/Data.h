#pragma once

#include "IncObjects/MovingObject.h"
#include "IncObjects/StaticObject.h"
#include "IncObjects/UserCar.h"
#include "IncObjects/ComputerCar.h"
#include "IncObjects/Barrel.h"
#include "FactoryObject.h"
#include "Map.h"
#include "macros.h"
#include <memory>

class Data {

public:
    Data();

    sf::Vector2f getUserPosition() const { return m_moving[User]->getPosition(); }

    void setObject(std::string &,
                   const sf::Vector2f &,
                   const sf::Vector2f &);

    void moveUserCar(const sf::Event &);

    void moveComputerCars(const sf::Event &);

    void drawData(sf::RenderWindow &);

    void setWorldStep();

private:
    void setWorld();

    std::unique_ptr<b2World> m_world;
    b2Body *m_groundBody;
    float m_timeStep = 1.0f / 60.0f;
    int32 m_velocityIterations = 6;
    int32 m_positionIterations = 2;
    Map m_map;
    std::vector<std::unique_ptr<MovingObject>> m_moving;
    std::vector<std::unique_ptr<StaticObject>> m_static;
};

