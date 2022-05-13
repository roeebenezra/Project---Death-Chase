#pragma once

#include "GameObject.h"

class MovingObject : public GameObject {

public:
    MovingObject(const int);

    void move(const sf::Event &);

private:

};