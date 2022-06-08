#pragma once

#include "GameObject.h"
#include "IncAnimation/HealthBar.h"
#include "IncAnimation/Explosion.h"

class MovingObject : public GameObject {

public:
    MovingObject(int,
                 std::unique_ptr<b2World> &,
                 const sf::Vector2f &,
                 const float,
                 b2BodyType,
                 int16);

    float getRotation() const { return m_sprite.getRotation(); }

    virtual ~MovingObject() = default;

    virtual void move(const sf::Event &) {}

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

private:
    bool m_carInWater = false;
    int m_carPLace = 17;
    bool m_carOnGround = true;
    HealthBar m_carHealth;
    Explosion m_carExplosion;
};