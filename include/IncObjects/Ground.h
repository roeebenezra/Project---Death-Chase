#pragma once

#include "StaticObject.h"
#include "IncBuildGame/FactoryObject.h"

class Ground : public StaticObject {
public:
    Ground(const unsigned&,
           std::unique_ptr<b2World> &,
           const sf::Vector2f &,
           const float&,
           const b2BodyType&,
           const int16&);

private:
    static bool m_registerGround_1;
    static bool m_registerGround_2;
    static bool m_registerGround_3;
    static bool m_registerGround_4;
    static bool m_registerGround_5;
    static bool m_registerGround_8;
    static bool m_registerGround_9;
};