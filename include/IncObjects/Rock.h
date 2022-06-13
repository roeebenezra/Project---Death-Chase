#pragma once

#include "StaticObject.h"
#include "IncBuildGame/FactoryObject.h"

class Rock : public StaticObject {

public:
    Rock(const unsigned&,
         std::unique_ptr<b2World> &,
         const sf::Vector2f &,
         const float&,
         const b2BodyType&,
         const int16&);

    void draw(sf::RenderWindow&) override;

private:
    static bool m_registerIt;
};