#pragma once

#include "StaticObject.h"
#include "FactoryObject.h"

class Water : public StaticObject {
public:
    Water(int,
           std::unique_ptr<b2World> &,
           const sf::Vector2f &,
           const float,
           b2BodyType,
           int16);

private:
    static bool m_registerIt;
};