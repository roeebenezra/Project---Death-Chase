#include "IncObjects/Box.h"

Box::Box(int name,
         std::unique_ptr<b2World> &world,
         const sf::Vector2f &position,
         const float rotation,
         b2BodyType bodyType,
         int16 group)
        : StaticObject(name, world, position, rotation, bodyType, group) {}

//_________________________________________________________________
bool Box::m_registerIt =
        FactoryObject<StaticObject>::registerIt("box", [](std::unique_ptr<b2World> &world,
                                                          const sf::Vector2f &position,
                                                          const float rotation) -> std::unique_ptr<StaticObject> {
            return std::make_unique<Box>(box, world, position, rotation, b2_dynamicBody, Collide);
        });

