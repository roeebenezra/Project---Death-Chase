#include "IncObjects/ComputerCar.h"

ComputerCar::ComputerCar(const int name) : MovingObject(name) {}

//_____________________________________________
void ComputerCar::move(const sf::Event &event) {
    setMove(sf::Vector2f(1, 0) * (3.f));
}
