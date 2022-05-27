#include "IncObjects/ComputerCar.h"

ComputerCar::ComputerCar(int name,
                         std::unique_ptr<b2World> &world,
                         const sf::Vector2f &position,
                         const sf::Vector2f &scale,
                         b2BodyType bodyType) :
        MovingObject(name, world, position, scale, bodyType) {}

//_________________________________
bool ComputerCar::m_registerRedCar = FactoryObject<MovingObject>::registerIt("redCar",
                                                                             [](std::unique_ptr<b2World> &world,
                                                                                const sf::Vector2f &position,
                                                                                const sf::Vector2f &scale) ->
                                                                                     std::unique_ptr<MovingObject> {
                                                                                 return std::make_unique<ComputerCar>(
                                                                                         redCar,
                                                                                         world,
                                                                                         position,
                                                                                         scale,
                                                                                         b2_dynamicBody);
                                                                             });

bool ComputerCar::m_registerGreenCar = FactoryObject<MovingObject>::registerIt("greenCar",
                                                                               [](std::unique_ptr<b2World> &world,
                                                                                  const sf::Vector2f &position,
                                                                                  const sf::Vector2f &scale) ->
                                                                                       std::unique_ptr<MovingObject> {
                                                                                   return std::make_unique<ComputerCar>(
                                                                                           greenCar,
                                                                                           world,
                                                                                           position,
                                                                                           scale,
                                                                                           b2_dynamicBody);
                                                                               });

//_____________________________________________
void ComputerCar::move(const sf::Event &event) {
    b2Vec2 dir = b2Vec2(1, 0);
    float impulse = m_body->GetMass() * 20;
    m_body->ApplyLinearImpulse(b2Vec2(impulse * dir.x, impulse * dir.y), m_body->GetWorldCenter(), true);
}
