#include "IncObjects/Water.h"

Water::Water(int name,
               std::unique_ptr<b2World> &world,
               const sf::Vector2f &position,
               const float rotation,
               b2BodyType bodyType,
               int16 group)
        : StaticObject(name, world, position, rotation, bodyType, group) {
    m_sprite.setColor(sf::Color(255, 255, 255, 128)); // half transparent
}

bool Water::m_registerIt =
        FactoryObject<StaticObject>::registerIt("water", [](std::unique_ptr<b2World> &world,
                                                             const sf::Vector2f &position,
                                                             const float rotation) -> std::unique_ptr<StaticObject> {
            return std::make_unique<Water>(water, world, position, rotation, b2_kinematicBody, SensorCollide);
        });

