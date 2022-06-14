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

    virtual void move(const sf::Event &) {}

    void setCarOnGround(const bool ground) { m_carOnGround = ground; }

    bool getCarOnGround() const { return m_carOnGround; }

    bool showHealthBar();

    void drawHealthBar(sf::RenderWindow &);

    void drawExplosion(sf::RenderWindow &);

    void drawCarPlace(sf::RenderWindow &);

    void setCarPlace(const int place) { m_carPLace = place; }

    void setCarInWater(const bool water) { m_carInWater = water; }

    bool getCarInWater() const { return m_carInWater; }

    void setCarAtFinishLine(const bool carAtFinishLine) { m_carAtFinishLine = carAtFinishLine; }

    bool getCarAtFinishLine() const { return m_carAtFinishLine; }

    void setCarOnGroundAngle(float carOnGround) { m_carOnGroundAngle = carOnGround; }

    float getCarOnGroundAngle() { return m_carOnGroundAngle; }

    void setPosition(const b2Vec2 &pos) { m_body->SetTransform(pos, m_body->GetAngle()); }

    void restartCar();

private:
    HealthBar m_carHealth;
    Explosion m_carExplosion;
    bool m_carAtFinishLine = false;
    float m_carOnGroundAngle = 0;
    bool m_carInWater = false;
    int m_carPLace;
    bool m_carOnGround = true;
};