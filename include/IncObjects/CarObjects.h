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

    ~CarObjects()override {
        m_body->DestroyFixture(m_body->GetFixtureList());
        m_bodyCircle1->DestroyFixture(m_bodyCircle1->GetFixtureList());
        m_bodyCircle2->DestroyFixture(m_bodyCircle2->GetFixtureList());
    }

    float getRotation() const { return m_sprite.getRotation(); }

    virtual void drawObjects(sf::RenderWindow &);

    virtual void moveCar(const b2Vec2 &){}

    virtual void move(const sf::Event &);

    void updateObjects() override;

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

    void setCarAtFinishLine(const bool carAtFinishLine) { m_carAtFinishLine = carAtFinishLine; }

    bool getCarAtFinishLine() const { return m_carAtFinishLine; }

    void setCarOnGroundAngle(float carOnGround) { m_carOnGroundAngle = carOnGround; }

    float getCarOnGroundAngle() { return m_carOnGroundAngle; }

    void setPosition(const b2Vec2 &pos) { m_body->SetTransform(pos, m_body->GetAngle()); }

    void restartCar();

protected:
    Sprite m_tire1;
    Sprite m_tire2;
    b2Body *m_bodyCircle1;
    b2Body *m_bodyCircle2;
    b2RevoluteJoint *m_revoluteJoint1;
    b2RevoluteJoint *m_revoluteJoint2;
private:

    void setB2d(std::unique_ptr<b2World> &, b2BodyType, int16);
    HealthBar m_carHealth;
    Explosion m_carExplosion;
    bool m_carAtFinishLine = false;
    float m_carOnGroundAngle = 0;
    bool m_carInWater = false;

    int m_carPLace;

    bool m_carOnGround = true;
};