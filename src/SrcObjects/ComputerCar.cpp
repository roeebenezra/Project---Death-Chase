#include "IncObjects/ComputerCar.h"

ComputerCar::ComputerCar(const unsigned& name,
                         std::unique_ptr<b2World> &world,
                         const sf::Vector2f &position,
                         const float& rotation,
                         const b2BodyType& bodyType,
                         const int16& group) :
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
    float rotation1 = m_tire1.getRotation();
    float rotation2 = m_tire2.getRotation();

    m_tire1.setRotation(rotation1 + 20.0f);
    m_tire2.setRotation(rotation2 + 20.0f);

    b2Vec2 dir = b2Vec2(1, 0);
    float impulse = m_body->GetMass() * 0.8f;
    m_body->ApplyLinearImpulse(b2Vec2(impulse * dir.x, 0), m_body->GetWorldCenter(), true);
}

//___________________________________________
void ComputerCar::draw(sf::RenderWindow &window) {
    window.draw(m_sprite);
    drawHealthBar(window);
    drawExplosion(window);
    drawCarPlace(window);
}
