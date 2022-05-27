#include "MyContactListener.h"

void MyContactListener::BeginContact(b2Contact *contact) {
    auto a = static_cast<GameObject*> (contact->GetFixtureA()->GetBody()->GetUserData());
    auto b = static_cast<GameObject*> (contact->GetFixtureB()->GetBody()->GetUserData());
    HandleCollision::instance().processCollision(a, b);
}