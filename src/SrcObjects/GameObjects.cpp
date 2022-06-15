
#include "IncObjects/GameObject.h"

//________________________________________
GameObject::GameObject(const unsigned &name,
                       std::unique_ptr<b2World> &world,
                       const sf::Vector2f &position,
                       const float &rotation,
                       const b2BodyType &bodyType,
                       const int16 &group) {
    setSprite(name, position, rotation);
    setB2d(world, bodyType, group);
}

//___________________________________________
void GameObject::setSprite(const unsigned &name,
                           const sf::Vector2f &position,
                           const float &rotation) {
    m_sprite.setTexture(Resources::instance().getTexture(name));
    m_sprite.setPosition(position);
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
    m_sprite.setRotation(rotation);
}

//_____________________________________________________
void GameObject::setB2d(std::unique_ptr<b2World> &world,
                        b2BodyType bodyType,
                        int16 group) {
    b2BodyDef bodyDef; // BodyDef
    bodyDef.type = bodyType;
    bodyDef.angle = m_sprite.getRotation();
    bodyDef.position.Set(getPosition().x, getPosition().y);

    m_body = world->CreateBody(&bodyDef); // set Body to world

    b2PolygonShape BoxShape; // set BoxShape
    BoxShape.SetAsBox(float(getWidth()) / 2, float(getHeight()) / 2);

    b2FixtureDef fixtureDef; // FixtureDef
    fixtureDef.shape = &BoxShape;
    fixtureDef.density = 1;
//    m_body->ResetMassData();
    fixtureDef.friction = 1;
    fixtureDef.filter.groupIndex = group;
    m_body->CreateFixture(&fixtureDef);
    m_body->SetUserData(this);
}

//______________________________
void GameObject::updateObjects() {
    b2Vec2 position = m_body->GetPosition();
    m_sprite.setPosition(position.x, position.y);
    float angle = 180 / b2_pi * m_body->GetAngle(); //body angle multiply by 180/pie
    m_sprite.setRotation(angle);
}

//_____________________________________________
void GameObject::draw(sf::RenderWindow &window) {
    window.draw(m_sprite);
}