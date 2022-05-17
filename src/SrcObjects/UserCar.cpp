#include "IncObjects/UserCar.h"


bool UserCar::m_registerIt = FactoryObject<MovingObject>::registerIt("userCar",
                                                       []()-> std::unique_ptr<MovingObject> { return std::make_unique<UserCar>(userCar); });

//________________________________
UserCar::UserCar(const int name) :
        MovingObject(name) {}

//__________________________________________
void UserCar::move(const sf::Event &event) {
    setMove(keyToDirection(event.key.code) * moveSpeed);
}
