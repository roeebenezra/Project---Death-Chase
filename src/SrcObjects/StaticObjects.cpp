#include "IncObjects/StaticObject.h"

//_____________________________________________
StaticObject::StaticObject(const unsigned& name,
                           std::unique_ptr<b2World> &world,
                           const sf::Vector2f &position,
                           const float& rotation,
                           const b2BodyType& bodyType,
                           const int16& group)
        : GameObject(name, world, position, rotation, bodyType, group) {}