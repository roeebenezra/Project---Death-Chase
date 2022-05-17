#include "IncObjects/ComputerCar.h"

bool ComputerCar::m_registerRedCar = FactoryObject<MovingObject>::registerIt("redCar", []()-> std::unique_ptr<MovingObject> { return std::make_unique<ComputerCar>(redCar); });

bool ComputerCar::m_registerGreenCar = FactoryObject<MovingObject>::registerIt("greenCar", []()-> std::unique_ptr<MovingObject> { return std::make_unique<ComputerCar>(greenCar); });

ComputerCar::ComputerCar(const int name) : MovingObject(name) {}

//_____________________________________________
void ComputerCar::move(const sf::Event &event) {
    setMove(sf::Vector2f(1, 0) * (2.f));
}
