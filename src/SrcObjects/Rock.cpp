#include "IncObjects/Rock.h"

//_______________________
Rock::Rock(const unsigned& name,
           std::unique_ptr<b2World> &world,
           const sf::Vector2f &position,
           const float& rotation,
           const b2BodyType& bodyType,
           const int16& group) :
        StaticObject(name, world, position, rotation, bodyType, group) {

    m_body->DestroyFixture(m_body->GetFixtureList()); // destroy rock old fixture

    b2CircleShape circleShape;
    circleShape.m_p.Set(m_sprite.getOrigin().x / 30, m_sprite.getOrigin().y / 30); //position, relative to body position
    circleShape.m_radius = 150; //radius

    b2FixtureDef fixtureDef; // FixtureDef
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 1.0f;

    m_body->CreateFixture(&fixtureDef); // create new fixture for the rock
}

//__________________________
bool Rock::m_registerIt =
        FactoryObject<StaticObject>::registerIt("rock", [](std::unique_ptr<b2World> &world,
                                                           const sf::Vector2f &position,
                                                           const float rotation) -> std::unique_ptr<StaticObject> {
            return std::make_unique<Rock>(rock, world, position, rotation, b2_kinematicBody, GroundCollide);
        });

//_____________________________________________
void Rock::draw(sf::RenderWindow &window) {
    float angle = 0.3f;
//    angle = angle > 1.0f ?  0.1f : angle += 0.1f;
    m_body->SetTransform(m_body->GetPosition(), m_body->GetAngle() + (angle * b2_pi / 180));
    window.draw(m_sprite);
}