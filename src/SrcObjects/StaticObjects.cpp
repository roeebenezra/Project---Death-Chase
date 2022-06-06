#include "IncObjects/StaticObject.h"

//______________________________________
StaticObject::StaticObject(const unsigned name,
                           std::unique_ptr<b2World> &world,
                           const sf::Vector2f &position,
                           const sf::Vector2f &scale,
                           b2BodyType bodyType)
        : GameObject(name, world, position, scale, bodyType) {}