#include "IncObjects/MovingObject.h"

//________________________________________
MovingObject::MovingObject(const int name,
                           const sf::Vector2f &position,
                           const sf::Vector2f &scale)
        : GameObject(name, position, scale) {}