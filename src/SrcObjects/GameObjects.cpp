#include "IncObjects/GameObject.h"

//______________________________
GameObject::GameObject(int name,
                       std::unique_ptr<b2World> &world,
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
    m_sprite.setTexture(Resources::instance().getTexture(name));
    m_sprite.setPosition(position);
//    if(scale.x == 20)
//        m_sprite.setRotation(-20);
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
//    m_sprite.setScale(scale);
}

//________________________________________________________________________
void GameObject::setB2d(std::unique_ptr<b2World> &world, b2BodyType bodyType) {
    // BodyDef
    b2BodyDef bodyDef;
    bodyDef.type = bodyType;
    bodyDef.position.Set(getPosition().x, getPosition().y);
    bodyDef.angle = m_sprite.getRotation();
    // set Body to world
    m_body = world->CreateBody(&bodyDef);

    // set BoxShape
    b2PolygonShape BoxShape;
    BoxShape.SetAsBox(getWidth() / 2, getHeight() / 2);

    // FixtureDef
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &BoxShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 1.0f;

    m_body->CreateFixture(&fixtureDef);
    m_body->SetUserData(this);
}

//_____________________________________________
void GameObject::draw(sf::RenderWindow &window) {
    b2Vec2 position = m_body->GetPosition();
    m_sprite.setPosition(position.x, position.y);

    float angle = m_body->GetAngle();
    m_sprite.setRotation(angle);

    window.draw(m_sprite);
}