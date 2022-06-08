#pragma once

#include "IncAnimation/AnimationObjects.h"

class Explosion : public AnimationObjects {

public:
    Explosion(const sf::Vector2f &pos,
         const sf::Vector2f &scale) : AnimationObjects(pos, scale, Resources::Explosion, explosion, explosionTime) {}
};