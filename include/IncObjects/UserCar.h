#pragma once

#include "MovingObject.h"
#include "FactoryObject.h"
#include "macros.h"
#include <memory>

class UserCar : public MovingObject {

public:
    UserCar(const int);

    void move(const sf::Event &) override;

    static bool m_registerIt;
};
