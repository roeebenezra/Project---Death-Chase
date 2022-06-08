#include "IncObjects/StaticObject.h"

//______________________________________
StaticObject::StaticObject(const unsigned name,
                           std::unique_ptr<b2World> &world,
                           const sf::Vector2f &position,
                           const float rotation,
                           b2BodyType bodyType,
                           int16 group)
        : GameObject(name, world, position, rotation, bodyType, group) {}