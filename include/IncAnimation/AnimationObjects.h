#pragma once

#include "IncAnimation/Animation.h"
#include "IncBuildGame/Resources.h"

class AnimationObjects {

public:
    AnimationObjects(const sf::Vector2f &,
                     const sf::Vector2f &,
                     Resources::Objects,
                     const int,
                     const float);

    void draw(sf::RenderWindow &window) const { window.draw(m_sprite); }

    void update(const sf::Vector2f &, const sf::Vector2f &);

    bool getAnimationIndex() const { return m_animation.getIndex(); }

    void setAnimationIndex(const int& index) { m_animation.setIndex(index); }

private:
    sf::Sprite m_sprite;
    sf::Clock m_aiTime;
    Animation m_animation;
    float m_animationTime;
};