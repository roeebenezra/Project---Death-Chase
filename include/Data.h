#pragma once

#include "IncObjects/MovingObject.h"
#include "IncObjects/StaticObject.h"
#include "IncObjects/UserCar.h"
#include "IncObjects/ComputerCar.h"
#include "IncObjects/Barrel.h"
#include "IncMenus/GameMenu.h"
#include "FactoryObject.h"
#include "Map.h"
#include "macros.h"

class Data {
public:
    Data();

    const sf::Vector2f getUserPosition() const { return m_moving[User]->getPosition(); }

    void setObject(std::string &,
                   const sf::Vector2f &,
                   const float);

    void moveUserCar(const sf::Event &);

    void moveComputerCars(const sf::Event &);

    void drawData(sf::RenderWindow &, const unique_ptr<GameMenu> &);

    void setWorldStep();

    std::unique_ptr<b2World> &getWorld() { return m_world; }

    void removeObjects();

    void setCarsPlace();

private:
    void setWorld();

    void setView(sf::RenderWindow &window, float width, float height) const;

    std::unique_ptr<b2World> m_world;

    float m_timeStep = 1.0f / 60.0f;
    int32 m_velocityIterations = 8;
    int32 m_positionIterations = 3;

    Map m_map;
    std::vector<std::unique_ptr<MovingObject>> m_moving;
    std::vector<std::unique_ptr<StaticObject>> m_static;
};

