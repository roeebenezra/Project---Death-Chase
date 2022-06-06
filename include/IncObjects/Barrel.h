#pragma once

#include "StaticObject.h"
#include "FactoryObject.h"
#include "macros.h"

class Barrel : public StaticObject {

public:
    Barrel(unsigned,
           std::unique_ptr<b2World> &,
           const sf::Vector2f &,
           const sf::Vector2f &,
           b2BodyType);

    static bool m_registerIt;
};