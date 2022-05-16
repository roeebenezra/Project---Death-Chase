#include "IncObjects/UserCar.h"

//________________________________
UserCar::UserCar(const int name) :
        MovingObject(name) {}

//__________________________________________
void UserCar::move(const sf::Event &event) {
    setMove(keyToDirection(event.key.code) * moveSpeed);
}
