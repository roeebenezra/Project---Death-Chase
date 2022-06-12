#include "IncAnimation/AnimationObjects.h"

AnimationObjects::AnimationObjects(const sf::Vector2f &pos,
                                   const sf::Vector2f &scale,
                                   Resources::Objects object,
                                   const int name,
                                   const float animationTime)
        : m_animation(Resources::instance().animationData(object),
                      Direction::Right, m_sprite, name), m_animationTime(animationTime) {
    m_sprite.setPosition(pos);
    m_sprite.setScale(scale);
}

void AnimationObjects::update(const sf::Vector2f &pos, const sf::Vector2f & offset) {
    m_sprite.setPosition(sf::Vector2f(pos.x + offset.x , pos.y + offset.y));
    m_animation.update(m_animationTime);
}