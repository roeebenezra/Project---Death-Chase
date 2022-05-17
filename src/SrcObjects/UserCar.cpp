#include "IncObjects/UserCar.h"


bool UserCar::m_registerIt = FactoryObject<MovingObject>::registerIt("userCar",
                                                                     [](const sf::Vector2f &position,
                                                                        const sf::Vector2f &scale) ->
                                                                             std::unique_ptr<MovingObject> {
                                                                         return std::make_unique<UserCar>(userCar,
                                                                                                          position,
                                                                                                          scale);
                                                                     });

//________________________________
UserCar::UserCar(const int name,
                 const sf::Vector2f &position,
                 const sf::Vector2f &scale) :
        MovingObject(name, position, scale) {}

//__________________________________________
void UserCar::move(const sf::Event &event) {
    setMove(keyToDirection(event.key.code) * moveSpeed);
}
