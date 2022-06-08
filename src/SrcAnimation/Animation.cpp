#include "IncAnimation/Animation.h"
#include "Resources.h"

Animation::Animation(const AnimationData &data, Direction dir, sf::Sprite &sprite, const int name)
        : m_data(data), m_dir(dir), m_sprite(sprite) {
    m_sprite.setTexture(Resources::instance().getTexture(name));
    update();
}

void Animation::direction(Direction dir) {
    if (m_dir == dir || dir == Direction::Stay)
        return;

    m_dir = dir;
    update();
}

void Animation::update(const float animationTime) {
    if (m_animationClock.getElapsedTime().asSeconds() >= animationTime) {
        ++m_index;
        m_index %= m_data.m_data.find(m_dir)->second.size();
        m_animationClock.restart();
        update();
    }
}

void Animation::update() {
    m_sprite.setTextureRect(m_data.m_data.find(m_dir)->second[unsigned(m_index)]);
}