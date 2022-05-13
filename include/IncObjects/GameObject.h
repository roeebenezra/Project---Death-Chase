#pragma once

#include "macros.h"

class GameObject {

public:
    GameObject(const int);

    void draw(sf::RenderWindow &) const;

    sf::Vector2f getPosition() const { return m_shape.getPosition(); }

    void setMove(const sf::Vector2f &);
//	void collision();

private:
    sf::Sprite m_shape;
};