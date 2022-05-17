#pragma once

#include "GameObject.h"

class StaticObject : public GameObject {

public:
    StaticObject(const int, const sf::Vector2f&, const sf::Vector2f&);

//    ~StaticObject() = default;
};
