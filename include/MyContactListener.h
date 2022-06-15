#pragma once
#include "macros.h"
#include "HandleCollision.h"

class MyContactListener : public b2ContactListener {
    void BeginContact(b2Contact *contact)override;
    void setFixtureCollision(b2Contact* contact, const int16&, const bool&);
    b2Filter getFilerSet(b2Contact*, int, int16);
};
