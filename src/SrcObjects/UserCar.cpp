#include "IncObjects/UserCar.h"

//_______________________
UserCar::UserCar(int name,
                 std::unique_ptr<b2World> &world,
                 const sf::Vector2f &position,
                 const sf::Vector2f &scale,
                 b2BodyType bodyType) :
        MovingObject(name, world, position, scale, bodyType) {}

//_________________________________________________________________
bool UserCar::m_registerIt = FactoryObject<MovingObject>::registerIt("userCar",
                                                                     [](std::unique_ptr<b2World> &world,
                                                                        const sf::Vector2f &position,
                                                                        const sf::Vector2f &scale) ->
                                                                             std::unique_ptr<MovingObject> {
                                                                         return std::make_unique<UserCar>(userCar,
                                                                                                          world,
                                                                                                          position,
                                                                                                          scale,
                                                                                                          b2_dynamicBody);
                                                                     });


//__________________________________________
void UserCar::move(const sf::Event &event) {
    setMove(keyToDirection(event.key.code));
}
