#pragma once

#include "MovingObject.h"
#include "FactoryObject.h"

class ComputerCar : public MovingObject {

public:
    ComputerCar(unsigned,
                std::unique_ptr<b2World> &,
                const sf::Vector2f &,
                const float,
                b2BodyType,
                int16);

    void move(const sf::Event &) override;

    void draw(sf::RenderWindow &) override;

private:
    static bool m_registerRedCar;
    static bool m_registerGreenCar;
};