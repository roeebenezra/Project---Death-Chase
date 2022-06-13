#include "IncAnimation/Coin.h"

Coin::Coin(const unsigned& name,
    std::unique_ptr<b2World> &world,
    const sf::Vector2f &position,
    const float& rotation,
    const b2BodyType& bodyType,
    const int16& group)
        : StaticObject(name, world, position, rotation, bodyType, group),
          m_animation(Resources::instance().animationData(Resources::Coin),
                      Direction::Right, m_sprite, coin) {
//    m_body->DestroyFixture(m_body->GetFixtureList()); // destroy rock old fixture

//    b2CircleShape circleShape;
//    circleShape.m_p.Set(m_sprite.getOrigin().x / 210, m_sprite.getOrigin().y / 210); //position, relative to body position
//    circleShape.m_radius = 40; //radius

//    b2FixtureDef fixtureDef; // FixtureDef
//    fixtureDef.shape = &circleShape;
//    fixtureDef.density = 1.0f;
//    fixtureDef.friction = 1.0f;
//    m_body->
//    b2PolygonShape BoxShape; // set BoxShape
//    BoxShape.SetAsBox(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
//
//    b2FixtureDef fixtureDef; // FixtureDef
//    fixtureDef.shape = &BoxShape;
//    fixtureDef.density = 1.0f;
//    fixtureDef.friction = 1.0f;
//    fixtureDef.filter.groupIndex = group;
////    m_body->CreateFixture(&fixtureDef);
//
//    m_body->CreateFixture(&fixtureDef); // create new fixture for the rock
//    m_body->GetFixtureList()->SetSensor(true);
}

//______________________________________________________________________
bool Coin::m_registerIt =
        FactoryObject<StaticObject>::registerIt("coin", [](std::unique_ptr<b2World> &world,
                                                           const sf::Vector2f &position,
                                                           const float rotation) -> std::unique_ptr<StaticObject> {
            return std::make_unique<Coin>(coin, world, position, rotation, b2_kinematicBody, SensorCollide);
        });

//________________________________________
void Coin::draw(sf::RenderWindow &window) {
    m_animation.update(coinTime);
    window.draw(m_sprite);
}