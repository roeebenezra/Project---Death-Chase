#include "IncObjects/Barrel.h"

Barrel::Barrel(unsigned name,
               std::unique_ptr<b2World> &world,
               const sf::Vector2f &position,
               const float rotation,
               b2BodyType bodyType,
               int16 group)
        : StaticObject(name, world, position, rotation, bodyType, group) {}

bool Barrel::m_registerIt =
        FactoryObject<StaticObject>::registerIt("barrel", [](std::unique_ptr<b2World> &world,
                                                             const sf::Vector2f &position,
                                                             const float rotation) -> std::unique_ptr<StaticObject> {
            return std::make_unique<Barrel>(barrel, world, position, rotation, b2_dynamicBody, Collide);
        });

