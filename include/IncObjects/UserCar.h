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

    void setB2d(std::unique_ptr<b2World> &world,
                b2BodyType bodyType,
                int16 group )override;

    void move(const sf::Event &) override;

    void draw(sf::RenderWindow &) override;

    float getCarZoomView();

    bool isCarMoving() const {
        return m_body->GetMass() * moveSpeed * m_carTimeDir.getElapsedTime().asSeconds() > 1.99818e+07;
    }

    void setCarOnGroundAngle(const float &angle) { m_groundAngle = angle; }

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
    float m_carZoomView = 1.0f;
    Dust m_dust;
    bool m_showDust = false;
    sf::Vector2f m_dustOffset;
    float m_groundAngle;

    b2Vec2 m_Dir = {1, 0};

    b2Body *m_bodyCircle1;
    b2Body *m_bodyCircle2;

    b2WheelJoint* m_joint;

    b2RevoluteJoint* m_revoluteJoint1;
    b2RevoluteJoint* m_revoluteJoint2;
};

