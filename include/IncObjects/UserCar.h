#pragma once

#include "MovingObject.h"
#include "FactoryObject.h"
#include "macros.h"
#include <memory>

class UserCar : public MovingObject {

public:
    UserCar(int,
            std::unique_ptr<b2World> &,
            const sf::Vector2f &,
            const sf::Vector2f &,
            b2BodyType);

    void move(const sf::Event &) override;

    static bool m_registerIt;
};
