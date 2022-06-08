#pragma once

#include "macros.h"
#include "IncAnimation/Animation.h"
#include "Resources.h"

class GameObject {
public:
    GameObject(int,
               std::unique_ptr<b2World> &,
               const sf::Vector2f &,
               const float,
               b2BodyType,
               int16);

    virtual void draw(sf::RenderWindow &);

    sf::Vector2f getPosition() const { return m_sprite.getPosition(); }

    void setCanCollide(const bool collide) { m_canCollide = collide; }

    bool getCanCollide() const { return m_canCollide; }

    void updateObjects();

    virtual ~GameObject() = default;

    void setObjectDead(const bool dead) { m_dead = dead; }

    bool getObjectDead() const { return m_dead; }

    void destroyBody() { m_body->GetWorld()->DestroyBody(m_body); }

protected:
    b2Body *m_body = nullptr;
    sf::Sprite m_sprite;

private:
    float getWidth() const { return m_sprite.getLocalBounds().width; }

    float getHeight() const { return m_sprite.getLocalBounds().height; }

    void setSprite(int, const sf::Vector2f &, const float);

    void setB2d(std::unique_ptr<b2World> &, b2BodyType, int16);

    bool m_canCollide = true;
    bool m_dead = false;
};