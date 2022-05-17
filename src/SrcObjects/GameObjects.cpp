#include "IncObjects/GameObject.h"

//_____________________________________
GameObject::GameObject(const int name,
                       const sf::Vector2f& postion,
                       const sf::Vector2f& scale) {
    m_shape.setTexture(Resources::instance().getTexture(name));
    m_shape.setPosition(postion);
    m_shape.setScale(scale);
}

//____________________________________________________
void GameObject::draw(sf::RenderWindow &window) const {
    window.draw(m_shape);
}

//________________________________________________
void GameObject::setMove(const sf::Vector2f &dir) {
    m_shape.move(dir);
}