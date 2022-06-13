#pragma once

#include "StaticObject.h"
#include "IncBuildGame/FactoryObject.h"

class Fence : public StaticObject {

public:
    Fence(const unsigned&,
           std::unique_ptr<b2World> &,
           const sf::Vector2f &,
           const float&,
          const b2BodyType&,
          const int16&);

private:
    static bool m_registerIt;
};