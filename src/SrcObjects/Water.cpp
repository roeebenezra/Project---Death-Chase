#include "IncObjects/Water.h"

Water::Water(const unsigned& name,
             std::unique_ptr<b2World> &world,
             const sf::Vector2f &position,
             const float& rotation,
             const b2BodyType& bodyType,
             const int16& group)
        : StaticObject(name, world, position, rotation, bodyType, group) {
    m_sprite.setColor(sf::Color(255, 255, 255, 128)); // half transparent
    m_body->GetFixtureList()->SetSensor(true);
}

bool Water::m_registerIt =
        FactoryObject<StaticObject>::registerIt("water", [](std::unique_ptr<b2World> &world,
                                                             const sf::Vector2f &position,
                                                             const float rotation) -> std::unique_ptr<StaticObject> {
            return std::make_unique<Water>(water, world, position, rotation, b2_kinematicBody, SensorCollide);
        });

