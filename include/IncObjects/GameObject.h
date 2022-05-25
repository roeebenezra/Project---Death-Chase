#pragma once

#include "macros.h"


class GameObject {
public:
    GameObject(int,
               std::unique_ptr<b2World> &,
               const sf::Vector2f &,
               const sf::Vector2f &,
               b2BodyType);

    void draw(sf::RenderWindow &);

    sf::Vector2f getPosition() const { return m_sprite.getPosition(); }

    float getWidth() const { return m_sprite.getLocalBounds().width; }

    float getHeight() const { return m_sprite.getLocalBounds().height; }

    void setMove(const b2Vec2 &);

protected:
    b2Body *m_body = nullptr;
private:
    void setSprite(int, const sf::Vector2f &, const sf::Vector2f &);
    void setB2d(std::unique_ptr<b2World> &, b2BodyType);
    std::string m_name;
    sf::Sprite m_sprite;
};