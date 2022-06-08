#pragma once

#include "MovingObject.h"
#include "FactoryObject.h"
#include "IncAnimation/Dust.h"

class UserCar : public MovingObject {

public:
    UserCar(unsigned,
            std::unique_ptr<b2World> &,
            const sf::Vector2f &,
            const float,
            b2BodyType,
            int16);

    void move(const sf::Event &) override;

    void draw(sf::RenderWindow &) override;

private:
    void updateDust(const sf::Keyboard::Key &);

    void setCarAngle(const sf::Keyboard::Key &);

    void moveCar(const b2Vec2&);

    static bool m_registerIt;

    sf::Keyboard::Key m_lastDir = sf::Keyboard::Right;
    double m_carAngle = 0;

    Dust m_dust;
    bool m_showDust = false;
    sf::Vector2f m_dustOffset;
};

//________
namespace {
    b2Vec2 keyToDirection(sf::Keyboard::Key key) {
        switch (key) {
            case sf::Keyboard::Up:
                return {1, 0};
            case sf::Keyboard::Down:
                return {-1, 0};
            default:
                return {0, 0};
        }

//        switch (key) {
//            case sf::Keyboard::Left:
//                return {-1, 0};
//            case sf::Keyboard::Right:
//                return {1, 0};
//            case sf::Keyboard::Up:
//                return {0, -1};
//            case sf::Keyboard::Down:
//                return {0, 1};
//            default:
//                return {0, 0};
//        }
    }

    const auto moveSpeed = 200.f;
}