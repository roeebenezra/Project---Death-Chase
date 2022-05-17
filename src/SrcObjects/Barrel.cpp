#include "IncObjects/Barrel.h"

bool Barrel::m_registerIt =
        FactoryObject<StaticObject>::registerIt
                ("barrel", [](const sf::Vector2f &position,
                              const sf::Vector2f &scale) -> std::unique_ptr<StaticObject> {
                    return std::make_unique<Barrel>(barrel, position, scale);
                });

Barrel::Barrel(const int name,
               const sf::Vector2f &position,
               const sf::Vector2f &scale)
        : StaticObject(name, position, scale) {}