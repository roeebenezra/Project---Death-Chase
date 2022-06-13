#include "MyContactListener.h"

void MyContactListener::BeginContact(b2Contact *contact) {
    auto a = static_cast<GameObject *> (contact->GetFixtureA()->GetBody()->GetUserData());
    auto b = static_cast<GameObject *> (contact->GetFixtureB()->GetBody()->GetUserData());

    if (contact->IsTouching())
        setFixtureCollision(contact, DontCollide, false);
    else
        setFixtureCollision(contact, Collide, true);

    HandleCollision::instance().processCollision(a, b);

}

void MyContactListener::setFixtureCollision(b2Contact *contact, const int16& collision, const bool& canCollide) {
    auto a = static_cast<GameObject *> (contact->GetFixtureA()->GetBody()->GetUserData());
    auto b = static_cast<GameObject *> (contact->GetFixtureB()->GetBody()->GetUserData());

    if ((contact->GetFixtureA()->GetFilterData().groupIndex == contact->GetFixtureB()->GetFilterData().groupIndex) &&
        !canCollide ? a->getCanCollide() && b->getCanCollide() : !a->getCanCollide() && !b->getCanCollide()) {

        contact->GetFixtureA()->SetFilterData(getFilerSet(contact, 1, collision)); // set filter to the wanted collide
        contact->GetFixtureB()->SetFilterData(getFilerSet(contact, 2, collision));

        a->setCanCollide(canCollide); // set object to collide
        b->setCanCollide(canCollide);
//        std::cout << "wont collide\n";
    }
}

b2Filter MyContactListener::getFilerSet(b2Contact *contact, int a, int16 collision) {
    if (a == 1) {
        b2Filter filter1 = contact->GetFixtureA()->GetFilterData();
        filter1.categoryBits = filter1.categoryBits;
        filter1.maskBits = filter1.maskBits;
        filter1.groupIndex = collision;
        return filter1;
    } else {
        b2Filter filter2 = contact->GetFixtureB()->GetFilterData();
        filter2.categoryBits = filter2.categoryBits;
        filter2.maskBits = filter2.maskBits;
        filter2.groupIndex = collision;
        return filter2;
    }
}