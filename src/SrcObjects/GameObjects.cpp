#include "IncObjects/GameObject.h"

//_____________________________
GameObject::GameObject(unsigned  name,
                       std::unique_ptr<b2World> &world,
                       const sf::Vector2f &position,
                       const float rotation,
                       b2BodyType bodyType,
                       int16 group) {
    setSprite(name, position, rotation);
    setB2d(world, bodyType, group);
}

//___________________________________________
void GameObject::setSprite(const unsigned name,
                           const sf::Vector2f &position,
                           const float rotation) {
    m_sprite.setTexture(Resources::instance().getTexture(name));
    m_sprite.setPosition(position);
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
    m_sprite.setRotation(rotation);
}

//______________________________________________________
void GameObject::setB2d(std::unique_ptr<b2World> &world,
                        b2BodyType bodyType,
                        int16 group) {
    // BodyDef
    b2BodyDef bodyDef;
    bodyDef.type = bodyType;
    bodyDef.angle = m_sprite.getRotation();
    bodyDef.position.Set(getPosition().x, getPosition().y);
    // set Body to world
    m_body = world->CreateBody(&bodyDef);

    // set BoxShape
    b2PolygonShape BoxShape;
    BoxShape.SetAsBox(getWidth() / 2, getHeight() / 2);

//     FixtureDef
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &BoxShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 1.0f;
    fixtureDef.filter.groupIndex = group;
    if (bodyType == b2_kinematicBody)
        fixtureDef.isSensor = true;
    m_body->CreateFixture(&fixtureDef);
    m_body->SetUserData(this);
}

//______________________________
void GameObject::updateObjects() {
    b2Vec2 position = m_body->GetPosition();
    m_sprite.setPosition(position.x, position.y);
    float angle = 180/b2_pi * m_body->GetAngle(); //body angle multiply by 180/pie
    m_sprite.setRotation(angle);
}

//_____________________________________________
void GameObject::draw(sf::RenderWindow &window) {
    window.draw(m_sprite);
}