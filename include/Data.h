#pragma once

#include "IncObjects/MovingObject.h"
#include "IncObjects/StaticObject.h"
#include "macros.h"

class Data {

public:
    Data();

    sf::Vector2f getUserPosition() const { return m_moving[0].getPosition(); }

    void moveData(const sf::Event &);

    void drawData(sf::RenderWindow &);

private:
    std::vector<MovingObject> m_moving;
    std::vector<StaticObject> m_static;
};

