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

    sf::Vector2f getPosition() const { return m_shape.getPosition(); }

    void setMove(const b2Vec2 &);

    void setB2d(std::unique_ptr<b2World> &, b2BodyType);


protected:
    b2Body *m_body = nullptr;
private:
    std::string m_name;

    void setSprite(int,
                   const sf::Vector2f &,
                   const sf::Vector2f &);

    b2Fixture *m_fixture = nullptr;
    b2PolygonShape m_dynamicBox;
    sf::Sprite m_shape;
};