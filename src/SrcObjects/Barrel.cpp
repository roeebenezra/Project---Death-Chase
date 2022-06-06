#include "IncObjects/Barrel.h"

Barrel::Barrel(unsigned name,
               std::unique_ptr<b2World> &world,
               const sf::Vector2f &position,
               const sf::Vector2f &scale,
               b2BodyType bodyType)
        : StaticObject(name, world, position, scale, bodyType) {}

//_________________________________________________________________
bool Barrel::m_registerIt = FactoryObject<StaticObject>::registerIt("barrel",
                                                                    [](std::unique_ptr<b2World> &world,
                                                                       const sf::Vector2f &position,
                                                                       const sf::Vector2f &scale) ->
                                                                            std::unique_ptr<StaticObject> {
                                                                        return std::make_unique<Barrel>(
                                                                                barrel,
                                                                                world,
                                                                                position,
                                                                                scale,
                                                                                b2_dynamicBody);
                                                                    });

