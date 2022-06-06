#pragma once

#include "StaticObject.h"
#include "FactoryObject.h"

class Ground : public StaticObject {
public:
    Ground(unsigned,
           std::unique_ptr<b2World> &,
           const sf::Vector2f &,
           const sf::Vector2f &,
           b2BodyType);

    static bool m_registerGround_1;
    static bool m_registerGround_2;
    static bool m_registerGround_3;
    static bool m_registerGround_4;
    static bool m_registerGround_5;
    static bool m_registerGround_8;
    static bool m_registerGround_9;
};