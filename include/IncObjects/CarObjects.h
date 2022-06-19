#pragma once

#include "GameObject.h"
#include "IncAnimation/HealthBar.h"
#include "IncAnimation/Explosion.h"

class CarObjects : public GameObject {

public:
    CarObjects(const unsigned &,
               std::unique_ptr<b2World> &,
               const sf::Vector2f &,
               const float &,
               const b2BodyType &,
               const int16 &);

    float getRotation() const { return m_sprite.getRotation(); }

    virtual void drawObjects(sf::RenderWindow &);

    virtual void move(const sf::Event &) {}

    void updateObjects() override;

    void setCarOnGround(const bool ground) { m_carOnGround = ground; }

    bool getCarOnGround() const { return m_carOnGround; }

    bool showHealthBar();

    void drawHealthBar(sf::RenderWindow &);

    void drawExplosion(sf::RenderWindow &);

    void drawCarPlace(sf::RenderWindow &);

    void setCarPlace(const unsigned place) { m_carPLace = place; }

    unsigned getCarPlace() const { return m_carPLace; }

    void setCarInWater(const bool water) { m_carInWater = water; }

    bool getCarInWater() const { return m_carInWater; }

    void setCarAtFinishLine(const bool carAtFinishLine) { m_carAtFinishLine = carAtFinishLine; }

    bool getCarAtFinishLine() const { return m_carAtFinishLine; }

    void setPosition(const b2Vec2 &pos) { m_body->SetTransform(pos, m_body->GetAngle()); }

    void coinsCounter() { m_coins++; }

    unsigned getCoins() const { return m_coins; }

    void restartCar();

protected:
    Sprite m_tire1;
    Sprite m_tire2;
    b2Body *m_bodyCircle1 = nullptr;
    b2Body *m_bodyCircle2 = nullptr;
    b2RevoluteJoint *m_revoluteJoint1 = nullptr;
    b2RevoluteJoint *m_revoluteJoint2 = nullptr;
private:
    void setSprites(const unsigned &);

    void setB2d(std::unique_ptr<b2World> &, b2BodyType, int16);

    void setCircles(std::unique_ptr<b2World> &, int16 &);

    void setJoints(std::unique_ptr<b2World> &);

    HealthBar m_carHealth;
    Explosion m_carExplosion;
    bool m_carAtFinishLine = false;
    float m_carOnGroundAngle = 0;
    bool m_carInWater = false;
    unsigned m_carPLace = 1;
    bool m_carOnGround = true;
    unsigned m_coins = 0;
};