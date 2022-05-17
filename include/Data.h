#pragma once

#include "IncObjects/MovingObject.h"
#include "IncObjects/StaticObject.h"
#include "IncObjects/UserCar.h"
#include "IncObjects/ComputerCar.h"
#include "IncObjects/Barrel.h"
#include "FactoryObject.h"
#include "macros.h"
#include <memory>

class Data {

public:
    Data();

    sf::Vector2f getUserPosition() const { return m_moving[User]->getPosition(); }

    void moveUserCar(const sf::Event &);
    void moveComputerCars(const sf::Event &);

    void drawData(sf::RenderWindow &);

private:
    std::vector<std::unique_ptr<MovingObject>> m_moving;
    std::vector<std::unique_ptr<StaticObject>> m_static;
};

