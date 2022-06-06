#pragma once

#include "macros.h"

class GameObject {
public:
    GameObject(unsigned,
               std::unique_ptr<b2World> &,
               const sf::Vector2f &,
               const sf::Vector2f &,
               b2BodyType);
    virtual ~GameObject() = default;
    void draw(sf::RenderWindow &);

    sf::Vector2f getPosition() const { return m_sprite.getPosition(); }

    virtual void move(const sf::Event &) {}
protected:
    b2Body *m_body = nullptr;

private:
    float getWidth() const { return m_sprite.getLocalBounds().width; }

    float getHeight() const { return m_sprite.getLocalBounds().height; }

    void setSprite(unsigned, const sf::Vector2f &, const sf::Vector2f &);

    void setB2d(std::unique_ptr<b2World> &, b2BodyType);

    sf::Sprite m_sprite;
};