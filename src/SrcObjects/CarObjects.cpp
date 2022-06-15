#include "IncObjects/CarObjects.h"

//______________________________________________
CarObjects::CarObjects(const unsigned &name,
                       std::unique_ptr<b2World> &world,
                       const sf::Vector2f &position,
                       const float &rotation,
                       const b2BodyType &bodyType,
                       const int16 &group)
        : GameObject(name, world, position, rotation, bodyType, group),
          m_carHealth(getPosition(), oppositeScale), m_carExplosion(getPosition(), regularScale) {
    setB2d(world, bodyType, group);
}

//______________________________________________________
void CarObjects::setB2d(std::unique_ptr<b2World> &world,
                        b2BodyType bodyType,
                        int16 group) {

    m_body->DestroyFixture(m_body->GetFixtureList());

    b2BodyDef bodyDef; // BodyDef
    bodyDef.type = bodyType;
    bodyDef.angle = m_sprite.getRotation();
    bodyDef.position.Set(getPosition().x, getPosition().y);

    m_body = world->CreateBody(&bodyDef); // set Body to world

    b2PolygonShape BoxShape; // set BoxShape
    BoxShape.SetAsBox(getWidth() / 2, getHeight() / 6);

    b2FixtureDef fixtureDef; // FixtureDef
    fixtureDef.shape = &BoxShape;
    fixtureDef.density = 1;
    fixtureDef.friction = 1;
    fixtureDef.filter.groupIndex = group;
    fixtureDef.isSensor = true;

    m_body->CreateFixture(&fixtureDef);
    m_body->SetUserData(this);

    //circles Def
    b2BodyDef bodyDefCircle1; // BodyDef
    b2BodyDef bodyDefCircle2; // BodyDef

    bodyDefCircle1.type = b2_dynamicBody;
    bodyDefCircle2.type = b2_dynamicBody;

    m_bodyCircle1 = world->CreateBody(&bodyDefCircle1); // set Body to world
    m_bodyCircle2 = world->CreateBody(&bodyDefCircle2); // set Body to world

    b2CircleShape CircleShape1;
    b2CircleShape CircleShape2;

    CircleShape1.m_p.Set(m_sprite.getPosition().x - 100,
                         m_sprite.getPosition().y + 30); //position, relative to body position
    CircleShape1.m_radius = 30; //radius

    CircleShape2.m_p.Set(m_sprite.getPosition().x + 120,
                         m_sprite.getPosition().y + 30); //position, relative to body position
    CircleShape2.m_radius = 30; //radius

    b2FixtureDef CircleFixtureDef1; // FixtureDef
    b2FixtureDef CircleFixtureDef2; // FixtureDef

    CircleFixtureDef1.shape = &CircleShape1;
    CircleFixtureDef2.shape = &CircleShape2;

    CircleFixtureDef1.density = 1;
    CircleFixtureDef2.density = 1;

    CircleFixtureDef1.filter.groupIndex = group;
    CircleFixtureDef2.filter.groupIndex = group;

    CircleFixtureDef1.friction = 1;
    CircleFixtureDef2.friction = 1;

    m_bodyCircle1->CreateFixture(&CircleFixtureDef1);
    m_bodyCircle2->CreateFixture(&CircleFixtureDef2);

    m_bodyCircle1->SetUserData(this);
    m_bodyCircle2->SetUserData(this);

    b2RevoluteJointDef revoluteJointDef1;
    b2RevoluteJointDef revoluteJointDef2;

    revoluteJointDef1.Initialize(m_bodyCircle1, m_body, m_bodyCircle1->GetWorldCenter());
    revoluteJointDef2.Initialize(m_bodyCircle2, m_body, m_bodyCircle2->GetWorldCenter());

    m_revoluteJoint1 = dynamic_cast<b2RevoluteJoint *>(world->CreateJoint(&revoluteJointDef1));
    m_revoluteJoint2 = dynamic_cast<b2RevoluteJoint *>(world->CreateJoint(&revoluteJointDef2));

    m_revoluteJoint1->SetUserData(this);
    m_revoluteJoint2->SetUserData(this);
}

//_________________________________
bool CarObjects::showHealthBar() {
    return (getCarOnGround() && getRotation() < 182 && getRotation() > 178 && m_carHealth.getAnimationIndex()) ||
           getCarInWater();
}

//_________________________________________________________
void CarObjects::drawHealthBar(sf::RenderWindow &window) {
    if (showHealthBar()) {
        m_carHealth.update(getPosition(), healthBarOffset);
        m_carHealth.draw(window);
    } else
        setCarOnGround(false);
}

//_________________________________________________________
void CarObjects::drawExplosion(sf::RenderWindow &window) {

    if (!m_carHealth.getAnimationIndex() /*&& m_carExplosion.getAnimationIndex()*/) {
        m_carExplosion.update(getPosition(), explosionOffset);
        m_carExplosion.draw(window);
    }
    if (!m_carExplosion.getAnimationIndex()) {
        m_carInWater = false;
        setObjectDead(true);
    }
}

//________________________________________________________
void CarObjects::drawCarPlace(sf::RenderWindow &window) {
    Sprite carPLaceSprite;
    carPLaceSprite.setTexture(Resources::instance().getTexture(m_carPLace));
    carPLaceSprite.setPosition({getPosition().x - carPlaceOffset, getPosition().y - carPlaceOffset});
    window.draw(carPLaceSprite);
}

//____________________________
void CarObjects::restartCar() {
    m_carHealth.setAnimationIndex(0);
    m_carExplosion.setAnimationIndex(0);
    m_carInWater = false;
}