#pragma once

#include "MovingObject.h"
#include "FactoryObject.h"

class ComputerCar : public MovingObject {

public:
    ComputerCar(unsigned,
                std::unique_ptr<b2World> &,
                const sf::Vector2f &,
                const sf::Vector2f &,
                b2BodyType);

    void move(const sf::Event &) override;

    static bool m_registerRedCar;
    static bool m_registerGreenCar;
};