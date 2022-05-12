#include "IncObjects/MovingObject.h"

//________
namespace {
    sf::Vector2f keyToDirection(sf::Keyboard::Key key) {
        switch (key) {
            case sf::Keyboard::Left:
                return {-1, 0};
            case sf::Keyboard::Right:
                return {1, 0};
            case sf::Keyboard::Up:
                return {0, -1};
            case sf::Keyboard::Down:
                return {0, 1};
            default:
                return {0, 0};
        }
    }
    const auto moveSpeed = 50.f;
}

//_________________________________________
MovingObject::MovingObject(const int name) :
        GameObject(name) {}

//______________________________________________
void MovingObject::move(const sf::Event &event) {
    setMove(keyToDirection(event.key.code) * moveSpeed);
}


