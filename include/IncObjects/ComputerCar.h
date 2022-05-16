#pragma once

#include "MovingObject.h"

class ComputerCar : public MovingObject {

public:
    ComputerCar(const int);
    void move(const sf::Event &) override;
};