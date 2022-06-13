#pragma once

#include "macros.h"
#include "IncObjects/GameObject.h"

class Boundaries : public GameObject {

public:
    Boundaries() : GameObject() {}

    void setBoundaries(std::unique_ptr<b2World> &world, const b2Vec2 &position) {
        b2BodyDef bodyDef; // BodyDef
        bodyDef.type = b2_kinematicBody;
        bodyDef.position.Set(position.x, position.y);

        m_body = world->CreateBody(&bodyDef); // set Body to world

        b2PolygonShape BoxShape; // set BoxShape
        BoxShape.SetAsBox(10, 10000);

        b2FixtureDef fixtureDef; // FixtureDef
        fixtureDef.shape = &BoxShape;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.0f;
        fixtureDef.filter.groupIndex = BoundariesCollide;
        m_body->CreateFixture(&fixtureDef);
        m_body->SetUserData(this);
    }
};