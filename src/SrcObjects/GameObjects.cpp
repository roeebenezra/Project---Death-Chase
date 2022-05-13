#include "IncObjects/GameObject.h"

//_____________________________________
GameObject::GameObject(const int name) {
    m_shape.setTexture(Resources::instance().getTexture(name));
    m_shape.setPosition(200, 200);
    m_shape.setScale(-0.2, 0.2);
}

//____________________________________________________
void GameObject::draw(sf::RenderWindow &window) const {
    window.draw(m_shape);
}

//________________________________________________
void GameObject::setMove(const sf::Vector2f &dir) {
    m_shape.move(dir);
}