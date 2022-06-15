#pragma once

#include "CarObjects.h"
#include "IncBuildGame/FactoryObject.h"
#include "IncAnimation/Dust.h"

class UserCar : public CarObjects {

public:
    UserCar(const unsigned &,
            std::unique_ptr<b2World> &,
            const sf::Vector2f &,
            const float &,
            const b2BodyType &,
            const int16 &);

    void move(const sf::Event &) override;

    void drawObjects(sf::RenderWindow &) override;

private:
    void updateDust(const b2Vec2 &);

    void setCarAngle(const sf::Keyboard::Key &);

    void moveCar(const b2Vec2 &);

    void drawDust(sf::RenderWindow &);

    b2Vec2 keyToDirection(sf::Keyboard::Key);

    static bool m_registerIt;
    b2Vec2 m_lastDir = {0, 0};
    sf::Clock m_carTimeDir;
    float m_carAngle = 0;
    Dust m_dust;
    bool m_showDust = false;
    sf::Vector2f m_dustOffset;
};

