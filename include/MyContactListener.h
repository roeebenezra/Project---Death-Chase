#pragma once

#include "macros.h"
#include "HandleCollision.h"

class MyContactListener : public b2ContactListener {

    void BeginContact(b2Contact *contact)override;
};
