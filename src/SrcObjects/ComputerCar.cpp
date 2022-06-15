#include "IncObjects/ComputerCar.h"

ComputerCar::ComputerCar(const unsigned &name,
                         std::unique_ptr<b2World> &world,
                         const sf::Vector2f &position,
                         const float &rotation,
                         const b2BodyType &bodyType,
                         const int16 &group) :
        CarObjects(name, world, position, rotation, bodyType, group) {

}

bool ComputerCar::m_registerRedCar =
        FactoryObject<CarObjects>::registerIt("redCar", [](std::unique_ptr<b2World> &world,
                                                           const sf::Vector2f &position,
                                                           const float rotation) -> std::unique_ptr<CarObjects> {
            return std::make_unique<ComputerCar>(redCar, world, position, rotation, b2_dynamicBody, Collide);
        });

bool ComputerCar::m_registerYellowCar =
        FactoryObject<CarObjects>::registerIt("yellowCar", [](std::unique_ptr<b2World> &world,
                                                              const sf::Vector2f &position,
                                                              const float rotation) -> std::unique_ptr<CarObjects> {
            return std::make_unique<ComputerCar>(yellowCar, world, position, rotation, b2_dynamicBody, Collide);
        });

bool ComputerCar::m_registerHummer =
        FactoryObject<CarObjects>::registerIt("hummer", [](std::unique_ptr<b2World> &world,
                                                           const sf::Vector2f &position,
                                                           const float rotation) -> std::unique_ptr<CarObjects> {
            return std::make_unique<ComputerCar>(hummer, world, position, rotation, b2_dynamicBody, Collide);
        });

bool ComputerCar::m_registerTruck =
        FactoryObject<CarObjects>::registerIt("truck", [](std::unique_ptr<b2World> &world,
                                                          const sf::Vector2f &position,
                                                          const float rotation) -> std::unique_ptr<CarObjects> {
            return std::make_unique<ComputerCar>(truck, world, position, rotation, b2_dynamicBody, Collide);
        });

//_______________________________________
void ComputerCar::move(const sf::Event &) {
    b2Vec2 dir = {1, 0};
    auto vel = m_body->GetLinearVelocity();
    auto desireVel = 80.0f;
    auto velChange = desireVel - vel.x;
    float impulse = m_body->GetMass() * velChange;

    m_body->ApplyLinearImpulse(impulse / 2* dir, m_bodyCircle1->GetWorldCenter(), true);
    m_body->ApplyLinearImpulse(impulse * dir, m_bodyCircle2->GetWorldCenter(), true);

    m_body->ApplyAngularImpulse(0.1f * m_body->GetInertia() * -m_body->GetAngularVelocity(), true);

    b2Vec2 currentForwardNormal = m_body->GetLinearVelocity();
    float currentForwardSpeed = currentForwardNormal.Normalize();
    float dragForceMagnitude = -2 * currentForwardSpeed;
    m_body->ApplyForce(dragForceMagnitude * currentForwardNormal, m_body->GetWorldCenter(), true);
}

//___________________________________________
void ComputerCar::draw(sf::RenderWindow &window) {
    window.draw(m_sprite);
    drawHealthBar(window);
    drawExplosion(window);
    drawCarPlace(window);
}
