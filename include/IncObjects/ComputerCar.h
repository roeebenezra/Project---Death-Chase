#pragma once

#include "MovingObject.h"
#include "FactoryObject.h"

class ComputerCar : public MovingObject {

public:
    ComputerCar(const int);
    void move(const sf::Event &) override;
    static bool m_registerRedCar;
    static bool m_registerGreenCar;
    ~ComputerCar(){}
};