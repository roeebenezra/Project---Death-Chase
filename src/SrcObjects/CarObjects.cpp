#include "IncObjects/CarObjects.h"

//______________________________________________
CarObjects::CarObjects(const unsigned &name,
                       std::unique_ptr<b2World> &world,
                       const sf::Vector2f &position,
                       const float &rotation,
                       const b2BodyType &bodyType,
                       const int16 &group)
        : GameObject(name, world, position, rotation, bodyType, group),
          m_carHealth(getPosition(), oppositeScale),
          m_carExplosion(getPosition(), regularScale) {

    setSprites(name);

    setB2d(world, bodyType, group);
}

//_____________________________________________
void CarObjects::setSprites(const unsigned &name) {
    m_tire1.setTexture(Resources::instance().getTexture(Tires));
    m_tire2.setTexture(Resources::instance().getTexture(Tires));

    m_tire1.setTextureRect(TireRects[name]);
    m_tire2.setTextureRect(TireRects[name]);

    m_tire1.setOrigin(float(m_tire1.getTextureRect().width) / 2, float(m_tire1.getTextureRect().height) / 2);
    m_tire2.setOrigin(float(m_tire2.getTextureRect().width) / 2, float(m_tire2.getTextureRect().height) / 2);

    m_tire1.setPosition(float(m_sprite.getPosition().x) - TireOffset[name].first.x,
                        float(m_sprite.getPosition().y + TireOffset[name].first.y));
    m_tire2.setPosition(float(m_sprite.getPosition().x) + TireOffset[name].second.x,
                        float(m_sprite.getPosition().y + TireOffset[name].second.y));

    if (name != yellowCar && name != hummer) {
        m_tire1.setScale(0.7f, 0.7f);
        m_tire2.setScale(0.7f, 0.7f);
    }
}

//______________________________________________________
void CarObjects::setB2d(std::unique_ptr<b2World> &world,
                        b2BodyType bodyType,
                        int16 group) {

    m_body->DestroyFixture(m_body->GetFixtureList());

    b2BodyDef bodyDef; // BodyDef
    bodyDef.type = bodyType;
    bodyDef.angle = m_sprite.getRotation();
    bodyDef.position.Set(m_sprite.getPosition().x, m_sprite.getPosition().y);

    m_body = world->CreateBody(&bodyDef); // set Body to world

    b2PolygonShape BoxShape; // set BoxShape
    BoxShape.SetAsBox(float(getWidth()) / 2, float(getHeight()) / 6);

    b2FixtureDef fixtureDef; // FixtureDef
    fixtureDef.shape = &BoxShape;
    fixtureDef.density = 1;
    fixtureDef.friction = 1;
    fixtureDef.filter.groupIndex = group;
    fixtureDef.isSensor = true;

    m_body->CreateFixture(&fixtureDef);
    m_body->SetUserData(this);

    //Circles Def
    setCircles(world, group);

    //Joints Def
    setJoints(world);
}

//________________________________________________________
void CarObjects::setCircles(std::unique_ptr<b2World> &world, int16& group) {
    b2BodyDef bodyDefCircle1; // CircleBodyDef
    b2BodyDef bodyDefCircle2; // CircleBodyDef

    bodyDefCircle1.type = b2_dynamicBody;
    bodyDefCircle2.type = b2_dynamicBody;

    m_bodyCircle1 = world->CreateBody(&bodyDefCircle1); // set Body to world
    m_bodyCircle2 = world->CreateBody(&bodyDefCircle2); // set Body to world

    b2CircleShape CircleShape1;
    b2CircleShape CircleShape2;

    CircleShape1.m_p.Set(m_tire1.getPosition().x, m_tire1.getPosition().y); //position, relative to body position
    CircleShape1.m_radius = 30; //radius

    CircleShape2.m_p.Set(m_tire2.getPosition().x, m_tire2.getPosition().y); //position, relative to body position
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
}

//________________________________________________________
void CarObjects::setJoints(std::unique_ptr<b2World> &world) {
    b2RevoluteJointDef revoluteJointDef1;
    b2RevoluteJointDef revoluteJointDef2;

    revoluteJointDef1.Initialize(m_bodyCircle1, m_body, m_bodyCircle1->GetWorldCenter());
    revoluteJointDef2.Initialize(m_bodyCircle2, m_body, m_bodyCircle2->GetWorldCenter());

    m_revoluteJoint1 = dynamic_cast<b2RevoluteJoint *>(world->CreateJoint(&revoluteJointDef1));
    m_revoluteJoint2 = dynamic_cast<b2RevoluteJoint *>(world->CreateJoint(&revoluteJointDef2));

    m_revoluteJoint1->SetUserData(this);
    m_revoluteJoint2->SetUserData(this);
}

//______________________________
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
    carPLaceSprite.setPosition({getPosition().x - carPlaceOffset, getPosition().y - carPlaceOffset - 50});
    window.draw(carPLaceSprite);
}

//____________________________
void CarObjects::restartCar() {
    m_carHealth.setAnimationIndex(0);
    m_carExplosion.setAnimationIndex(0);
}

//_____________________________________________
void CarObjects::drawObjects(sf::RenderWindow &window) {
    b2Vec2 position = m_body->GetPosition();
    window.draw(m_sprite);
    window.draw(m_tire1);
    window.draw(m_tire2);
    window.draw(m_sprite);
    drawHealthBar(window);
    drawExplosion(window);
    drawCarPlace(window);
}

//______________________________
void CarObjects::updateObjects() {
    b2Vec2 position = m_body->GetPosition();
    m_sprite.setPosition(position.x, position.y);

    m_tire1.setPosition(m_bodyCircle1->GetWorldCenter().x, m_bodyCircle1->GetWorldCenter().y);
    m_tire2.setPosition(m_bodyCircle2->GetWorldCenter().x, m_bodyCircle2->GetWorldCenter().y);

    float angle = 180 / b2_pi * m_body->GetAngle(); //body angle multiply by 180/pie
    m_sprite.setRotation(angle);
}