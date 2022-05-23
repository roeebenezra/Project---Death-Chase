#include "IncObjects/GameObject.h"

//__________________________
GameObject::GameObject(int name,
                       std::unique_ptr<b2World>& world,
                       const sf::Vector2f &position,
                       const sf::Vector2f &scale,
                       b2BodyType bodyType) {
    setSprite(name, position, scale);
    setB2d(world, bodyType);
}

//_______________________________________
void GameObject::setSprite(const int name,
                           const sf::Vector2f &position,
                           const sf::Vector2f &scale) {
    m_shape.setTexture(Resources::instance().getTexture(name));
    m_shape.setPosition(position);
    m_shape.setScale(scale);
}

//________________________________________________________________________
void GameObject::setB2d(std::unique_ptr<b2World> &world, b2BodyType bodyType)
{
    // BodyDef
    b2BodyDef bodyDef;
    bodyDef.type = bodyType;
    bodyDef.position.Set(m_shape.getPosition().x ,m_shape.getPosition().y );
    m_body = world->CreateBody(&bodyDef);

    // BoxShape
    b2PolygonShape BoxShape;
    BoxShape.SetAsBox(float (m_shape.getTexture()->getSize().x) / 30.f  , float (m_shape.getTexture()->getSize().y) / 30.f );

    // FixtureDef
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &BoxShape;
    if (bodyType == b2_dynamicBody)
    {
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 1.0f;
    }
    m_body->CreateFixture(&fixtureDef);
}

//_____________________________________________
void GameObject::draw(sf::RenderWindow &window) {
    b2Vec2 position = m_body->GetPosition();
   // position *= Scale;
    m_shape.setPosition(position.x, position.y);
    float angle = m_body->GetAngle();
    m_shape.setRotation(angle);
    window.draw(m_shape);
}

//______________________________________
void GameObject::setMove(const b2Vec2 &dir)
{
    float impulse = m_body->GetMass() * 10;
    m_body->ApplyLinearImpulse( b2Vec2(impulse,0), m_body->GetWorldCenter(),true );
}