#include "IncObjects/ComputerCar.h"

bool ComputerCar::m_registerRedCar =
        FactoryObject<MovingObject>::registerIt("redCar", [](const sf::Vector2f &position,
                                                             const sf::Vector2f &scale) -> std::unique_ptr<MovingObject> {
            return std::make_unique<ComputerCar>(redCar, position, scale);
        });

bool ComputerCar::m_registerGreenCar =
        FactoryObject<MovingObject>::registerIt("greenCar", [](const sf::Vector2f &position,
                                                               const sf::Vector2f &scale) -> std::unique_ptr<MovingObject> {
            return std::make_unique<ComputerCar>(greenCar, position, scale);
        });

ComputerCar::ComputerCar(const int name,
                         const sf::Vector2f &position,
                         const sf::Vector2f &scale)
        : MovingObject(name, position, scale) {}

//_____________________________________________
void ComputerCar::move(const sf::Event &event) {
    setMove(b2Vec2(1, 0));
}
