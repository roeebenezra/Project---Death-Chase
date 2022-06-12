#pragma once

#include "IncObjects/StaticObject.h"
#include "FactoryObject.h"

class Coin : public StaticObject {

public:
    Coin(int,
         std::unique_ptr<b2World> &,
         const sf::Vector2f &,
         const float,
         b2BodyType,
         int16);

    void draw(sf::RenderWindow &) override;

private:
    static bool m_registerIt;
    Animation m_animation;
    sf::Clock m_aiTime;
};