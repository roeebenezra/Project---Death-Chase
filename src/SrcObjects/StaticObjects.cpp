#include "IncObjects/StaticObject.h"

//________________________________________
StaticObject::StaticObject(const int name,
                           const sf::Vector2f &position,
                           const sf::Vector2f &scale)
        : GameObject(name, position, scale) {}