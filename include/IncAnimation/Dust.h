#pragma once

#include "IncAnimation/AnimationObjects.h"

class Dust : public AnimationObjects {

public:
    Dust(const sf::Vector2f &pos,
         const sf::Vector2f &scale) : AnimationObjects(pos, scale, Resources::Dust, dust, dustTime) {}
};