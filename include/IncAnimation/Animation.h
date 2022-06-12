#pragma once

#include "AnimationData.h"

class Animation {
public:
    Animation(const AnimationData &data, Direction dir, sf::Sprite &sprite, const int);

    // Set the direction; the sprite will take the relevant texture rect
    void direction(Direction dir);

    // Add more time to the elapsed time; if enough time passed, it
    // updates the sprite to show the next frame in the animation
    void update(const float);

    bool getIndex() const { return m_index + 1 != m_data.m_data.find(m_dir)->second.size(); }

private:
    // Update the sprite to take the correct part of the texture,
    // based on current dir and index
    void update();

    const AnimationData &m_data;
    sf::Clock m_animationClock;
    Direction m_dir = Direction::Up;
    int m_index = 0;
    sf::Sprite &m_sprite;
};
