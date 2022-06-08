#include "IncObjects/FinishLine.h"

FinishLine::FinishLine(int name,
             std::unique_ptr<b2World> &world,
             const sf::Vector2f &position,
             const float rotation,
             b2BodyType bodyType,
             int16 group)
        : StaticObject(name, world, position, rotation, bodyType, group) {
    m_sprite.setScale(1, 2);
}

bool FinishLine::m_registerIt =
        FactoryObject<StaticObject>::registerIt("finishLine", [](std::unique_ptr<b2World> &world,
                                                            const sf::Vector2f &position,
                                                            const float rotation) -> std::unique_ptr<StaticObject> {
            return std::make_unique<FinishLine>(finishLine, world, position, rotation, b2_kinematicBody, SensorCollide);
        });


