#pragma once

#include "IncAnimation/AnimationObjects.h"

class HealthBar : public AnimationObjects {

public:
    HealthBar(const sf::Vector2f &pos,
         const sf::Vector2f &scale) : AnimationObjects(pos, scale, Resources::HealthBar, healthBar, healthTime) {}
};
