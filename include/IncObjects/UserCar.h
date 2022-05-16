#pragma once

#include "MovingObject.h"

class UserCar : public MovingObject {

public:
    UserCar(const int);
    void move(const sf::Event &) override;
};