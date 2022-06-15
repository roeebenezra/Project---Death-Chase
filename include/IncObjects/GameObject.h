#pragma once

#include "macros.h"
#include "IncAnimation/Animation.h"
#include "IncBuildGame/Resources.h"

class GameObject {
public:
    GameObject(const unsigned&,
               std::unique_ptr<b2World> &,
               const sf::Vector2f &,
               const float&,
               const b2BodyType&,
               const int16&);

    GameObject() = default;

    virtual ~GameObject() { m_body->DestroyFixture(m_body->GetFixtureList()); }

    virtual void draw(sf::RenderWindow &);

    virtual void updateObjects();

    void setCanCollide(const bool collide) { m_canCollide = collide; }

    bool getCanCollide() const { return m_canCollide; }

    void setObjectDead(const bool dead) { m_dead = dead; }

    bool getObjectDead() const { return m_dead; }

    void destroyBody() { m_body->GetWorld()->DestroyBody(m_body); }

    float getAngle() const { return m_body->GetAngle(); }

    sf::Vector2f getPosition() const { return m_sprite.getPosition(); }

protected:
    b2Body *m_body = nullptr;
    sf::Sprite m_sprite;

    int getWidth() const { return m_sprite.getTextureRect().width; }

    int getHeight() const { return m_sprite.getTextureRect().height; }
private:
    void setSprite(const unsigned&, const sf::Vector2f &, const float&);

    void setB2d(std::unique_ptr<b2World> &, b2BodyType, int16);

    bool m_canCollide = true;
    bool m_dead = false;
};