#pragma once

#include "GameObject.h"

class StaticObject : public GameObject {
public:
    StaticObject(const unsigned&,
                 std::unique_ptr<b2World> &,
                 const sf::Vector2f &,
                 const float&,
                 const b2BodyType&,
                 const int16&);

};
