#pragma once

#include "GameObject.h"

class MovingObject : public GameObject {

public:
    MovingObject(unsigned,
                 std::unique_ptr<b2World> &,
                 const sf::Vector2f &,
                 const sf::Vector2f &,
                 b2BodyType);

    void move(const sf::Event &) override{}
};

//________
namespace {
    b2Vec2 keyToDirection(sf::Keyboard::Key key) {
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

    const auto moveSpeed = 200.f;
}