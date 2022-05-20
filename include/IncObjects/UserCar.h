#pragma once

#include "MovingObject.h"
#include "FactoryObject.h"
#include "macros.h"
#include <memory>

class UserCar : public MovingObject {

public:
    UserCar(const int,
            const sf::Vector2f&,
            const sf::Vector2f&);

    void move(const sf::Event &) override;

    static bool m_registerIt;
};
