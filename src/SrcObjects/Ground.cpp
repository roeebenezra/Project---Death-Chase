#include "IncObjects/Ground.h"

Ground::Ground(unsigned name,
               std::unique_ptr<b2World> &world,
               const sf::Vector2f &position,
               const float rotation,
               b2BodyType bodyType,
               int16 group)
        : StaticObject(name, world, position, rotation, bodyType, group) {}

bool Ground::m_registerGround_1 =
        FactoryObject<StaticObject>::registerIt("ground_1", [](std::unique_ptr<b2World> &world,
                                                               const sf::Vector2f &position,
                                                               const float rotation) -> std::unique_ptr<StaticObject> {
            return std::make_unique<Ground>(ground_1, world, position, rotation, b2_staticBody, GroundCollide);
        });

bool Ground::m_registerGround_2 =
        FactoryObject<StaticObject>::registerIt("ground_2", [](std::unique_ptr<b2World> &world,
                                                               const sf::Vector2f &position,
                                                               const float rotation) -> std::unique_ptr<StaticObject> {
            return std::make_unique<Ground>(ground_2, world, position, rotation, b2_staticBody, GroundCollide);
        });
bool Ground::m_registerGround_3 =
        FactoryObject<StaticObject>::registerIt("ground_3", [](std::unique_ptr<b2World> &world,
                                                               const sf::Vector2f &position,
                                                               const float rotation) -> std::unique_ptr<StaticObject> {
            return std::make_unique<Ground>(ground_3, world, position, rotation, b2_staticBody, GroundCollide);
        });
bool Ground::m_registerGround_4 =
        FactoryObject<StaticObject>::registerIt("ground_4", [](std::unique_ptr<b2World> &world,
                                                               const sf::Vector2f &position,
                                                               const float rotation) -> std::unique_ptr<StaticObject> {
            return std::make_unique<Ground>(ground_4, world, position, rotation, b2_staticBody, GroundCollide);

        });
bool Ground::m_registerGround_5 =
        FactoryObject<StaticObject>::registerIt("ground_5", [](std::unique_ptr<b2World> &world,
                                                               const sf::Vector2f &position,
                                                               const float rotation) -> std::unique_ptr<StaticObject> {
            return std::make_unique<Ground>(ground_5, world, position, rotation, b2_staticBody, GroundCollide);
        });

bool Ground::m_registerGround_8 =
        FactoryObject<StaticObject>::registerIt("ground_8", [](std::unique_ptr<b2World> &world,
                                                               const sf::Vector2f &position,
                                                               const float rotation) -> std::unique_ptr<StaticObject> {
            return std::make_unique<Ground>(ground_8, world, position, rotation, b2_staticBody, GroundCollide);
        });
bool Ground::m_registerGround_9 =
        FactoryObject<StaticObject>::registerIt("ground_9", [](std::unique_ptr<b2World> &world,
                                                               const sf::Vector2f &position,
                                                               const float rotation) -> std::unique_ptr<StaticObject> {
            return std::make_unique<Ground>(ground_9, world, position, rotation, b2_staticBody, GroundCollide);
        });

