#pragma once

#include "MovingObject.h"
#include "FactoryObject.h"

class ComputerCar : public MovingObject {

public:
    ComputerCar(const int, const sf::Vector2f&, const sf::Vector2f&);
    void move(const sf::Event &) override;
    static bool m_registerRedCar;
    static bool m_registerGreenCar;
    ~ComputerCar(){}
};