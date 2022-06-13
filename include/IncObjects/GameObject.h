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

    explicit GameObject() = default;

    virtual void draw(sf::RenderWindow &);

    sf::Vector2f getPosition() const { return m_sprite.getPosition(); }

    void setCanCollide(const bool collide) { m_canCollide = collide; }

    bool getCanCollide() const { return m_canCollide; }

    virtual void updateObjects();

    virtual ~GameObject() = default;

    void setObjectDead(const bool dead) { m_dead = dead; }

    bool getObjectDead() const { return m_dead; }

    void destroyBody() { m_body->GetWorld()->DestroyBody(m_body); }

    float getAngle() const { return m_body->GetAngle(); }

protected:
    b2Body *m_body = nullptr;
    sf::Sprite m_sprite;

private:
    void setSprite(const unsigned&, const sf::Vector2f &, const float&);

    void setB2d(std::unique_ptr<b2World> &, b2BodyType, int16);

    float getWidth() const { return m_sprite.getLocalBounds().width; }

    float getHeight() const { return m_sprite.getLocalBounds().height; }

    bool m_canCollide = true;
    bool m_dead = false;
};