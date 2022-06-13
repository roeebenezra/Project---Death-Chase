#pragma once

#include "macros.h"
#include "GameObject.h"

class Floor : public GameObject {

public:
    Floor() : GameObject() {}

    void setFloor(std::unique_ptr<b2World> &world) {
        b2BodyDef myBodyDef; //make a static floor to drop things on
        myBodyDef.type = b2_kinematicBody;

        myBodyDef.position.Set(0, 2500); //middle, bottom
        m_body = world->CreateBody(&myBodyDef);

        b2PolygonShape floor;
        floor.SetAsBox(40000, 10);

        b2FixtureDef fixtureDef; //     FixtureDef
        fixtureDef.shape = &floor;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.0f;
        fixtureDef.filter.groupIndex = FloorCollide;
        m_body->CreateFixture(&fixtureDef); //add a fixture to the body
        m_body->SetUserData(this);
    }
};
