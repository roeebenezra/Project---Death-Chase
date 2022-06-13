#pragma once

#include "GameObject.h"
#include "IncAnimation/HealthBar.h"
#include "IncAnimation/Explosion.h"

class MovingObject : public GameObject {

public:
    MovingObject(const unsigned&,
                 std::unique_ptr<b2World> &,
                 const sf::Vector2f &,
                 const float&,
                 const b2BodyType&,
                 const int16&);

    float getRotation() const { return m_sprite.getRotation(); }

    virtual ~MovingObject() = default;

    virtual void move(const sf::Event &) {}

//    void updateObjects() override;

    void setCarOnGround(const bool ground) { m_carOnGround = ground; }

    bool getCarOnGround() const { return m_carOnGround; }

    bool showHealthBar();

    void drawHealthBar(sf::RenderWindow &);

    void drawExplosion(sf::RenderWindow &);

    void drawCarPlace(sf::RenderWindow &);

    void setCarPlace(const int place) { m_carPLace = place; }

    int getCarPlace() { return m_carPLace; }

    void setCarInWater(const bool water) { m_carInWater = water; }

    bool getCarInWater() const { return m_carInWater; }

    void setCarOnGroundAngle(float carOnGround) { m_carOnGroundAngle = carOnGround; }

    float getCarOnGroundAngle() { return m_carOnGroundAngle; }

private:
    float m_carOnGroundAngle = 0;
    bool m_carInWater = false;
    int m_carPLace;
    bool m_carOnGround = true;
    HealthBar m_carHealth;
    Explosion m_carExplosion;
};