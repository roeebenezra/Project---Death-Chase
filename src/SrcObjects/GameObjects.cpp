#include "IncObjects/GameObject.h"

//_____________________________________
GameObject::GameObject(const int name,
                       const sf::Vector2f &position,
                       const sf::Vector2f &scale) {
    setSprite(name, position, scale);
}

//_______________________________________
void GameObject::setSprite(const int name,
                           const sf::Vector2f &position,
                           const sf::Vector2f &scale) {
    m_shape.setTexture(Resources::instance().getTexture(name));
    m_shape.setPosition(position);
    m_shape.setScale(scale);
}

//_______________________
void GameObject::setB2d(std::unique_ptr<b2World> &world) {
    m_bodyDef.type = b2_dynamicBody;
    m_bodyDef.position.Set(m_shape.getPosition().y / Scale, m_shape.getPosition().x / Scale);
    m_body = world->CreateBody(&m_bodyDef);
    m_dynamicBox.SetAsBox(1.0f, 1.0f);
    m_fixtureDef.shape = &m_dynamicBox;
    m_fixtureDef.density = 1.0f;
    m_fixtureDef.friction = 0.3f;
    m_body->CreateFixture(&m_fixtureDef);
}

//____________________________________________________
void GameObject::draw(sf::RenderWindow &window) const {
    window.draw(m_shape);
}

//________________________________________________
void GameObject::setMove(const b2Vec2 &dir) {
    std::cout << "m_shape.getPosition().x " <<  m_shape.getPosition().x << " " << "m_shape.getPosition().y " << m_shape.getPosition().y << "\n";
    std::cout << "m_body->GetPosition().x " <<  m_body->GetPosition().x << " " << "m_body->GetPosition().y " << m_body->GetPosition().y << "\n";
    m_body->SetLinearVelocity(b2Vec2(dir.x * 2, dir.y * 2));
    b2Vec2 position = m_body->GetPosition();
    position *= Scale;
    m_shape.setPosition(position.y, position.x);
    float angle = m_body->GetAngle();
    m_shape.setRotation(angle);
}