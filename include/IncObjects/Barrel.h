#pragma once

#include "StaticObject.h"
#include "FactoryObject.h"
#include "macros.h"

class Barrel : public StaticObject {

public:
    Barrel(const int,
           const sf::Vector2f&,
           const sf::Vector2f&);
    static bool m_registerIt;
};