#include "IncObjects/GameObject.h"

//_____________________________________
GameObject::GameObject(const int name,
                       const sf::Vector2f &position,
                       const sf::Vector2f &scale) {
    setSprite(name, position, scale);
    //setB2d()
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
void GameObject::setB2d(std::unique_ptr<b2World> &world) 
{
    // BodyDef
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(m_shape.getPosition().y / Scale, m_shape.getPosition().x / Scale);
    m_body = world->CreateBody(&bodyDef);
    
    // BoxShape
    b2PolygonShape BoxShape;
    BoxShape.SetAsBox(1.0f, 1.0f);

    // FixtureDef
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &BoxShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    m_fixture = m_body->CreateFixture(&fixtureDef);

}

//____________________________________________________
void GameObject::draw(sf::RenderWindow &window) const {
    window.draw(m_shape);
}

//________________________________________________
void GameObject::setMove(const b2Vec2 &dir) 
{
    //std::cout << "m_shape.getPosition().x " <<  m_shape.getPosition().x << " " << "m_shape.getPosition().y " << m_shape.getPosition().y << "\n";
    //std::cout << "m_body->GetPosition().x " <<  m_body->GetPosition().x << " " << "m_body->GetPosition().y " << m_body->GetPosition().y << "\n";
    m_body->SetLinearVelocity(b2Vec2(dir.x * 2, dir.y * 2));
    b2Vec2 position = m_body->GetPosition();
    position *= Scale;
    m_shape.setPosition(position.y, position.x);
    float angle = m_body->GetAngle();
    m_shape.setRotation(angle);
}