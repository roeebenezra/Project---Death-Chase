#pragma once

#include "IncObjects/CarObjects.h"
#include "IncObjects/StaticObject.h"
#include "IncObjects/UserCar.h"
#include "IncObjects/ComputerCar.h"
#include "IncObjects/Barrel.h"
#include "IncObjects//Floor.h"
#include "IncMenus/GameMenu.h"
#include "IncBuildGame/FactoryObject.h"
#include "IncBuildGame/Map.h"
#include "Boundaries.h"
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

    void handlePlayerDead();

    bool raceFinished() const;

    void drawData(sf::RenderWindow &);

    void setWorldStep();

    int didPlayerWin() const { return m_moving[User]->getCarPlace(); }

    unsigned getUserCoins() const { return m_moving[User]->getCoins(); }

    unsigned getIndexLevel() const { return m_indexLevel; }

    void setNextLevel(const unsigned &);

    std::unique_ptr<b2World> &getWorld() { return m_world; }

    void removeObjects();

    void setCarsPlace();

private:
    void setLevel();

    void setWorld();

    void setView(sf::RenderWindow &window, float width, float height) const;

    std::unique_ptr<b2World> m_world;
    Floor m_floor;
    Boundaries m_boundaries;

    float m_timeStep = 1.0f / 60.0f;
    int32 m_velocityIterations = 8;
    int32 m_positionIterations = 3;

    Map m_map;
    std::vector<std::unique_ptr<CarObjects>> m_moving;
    std::vector<std::unique_ptr<StaticObject>> m_static;
    unsigned m_indexLevel = 0;
};