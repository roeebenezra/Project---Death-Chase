#pragma once

#include "macros.h"


class GameObject {

public:
    GameObject(const int, const sf::Vector2f &, const sf::Vector2f &);

    void draw(sf::RenderWindow &) const;

    sf::Vector2f getPosition() const { return m_shape.getPosition(); }

    void setMove(const b2Vec2 &);

    void setB2d(std::unique_ptr<b2World> &);

private:
    std:: string m_name;
    void setSprite(const int,
                   const sf::Vector2f &,
                   const sf::Vector2f &);

    //b2BodyDef m_bodyDef;

    b2Body *m_body = nullptr ;
    b2Fixture *m_fixture = nullptr;
    b2PolygonShape m_dynamicBox;
    
    //b2FixtureDef m_fixtureDef;
    sf::Sprite m_shape;
};