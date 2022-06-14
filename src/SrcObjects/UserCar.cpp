#include "IncObjects/UserCar.h"

//____________________________________
UserCar::UserCar(const unsigned &name,
                 std::unique_ptr<b2World> &world,
                 const sf::Vector2f &position,
                 const float &rotation,
                 const b2BodyType &bodyType,
                 const int16 &group) :
        CarObjects(name, world, position, rotation, bodyType, group),
        m_dust(getPosition(), regularScale) {
    setB2d(world, bodyType, group);
}

//______________________________________________________
void UserCar::setB2d(std::unique_ptr<b2World> &world,
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
//    m_body->SetLinearVelocity(b2Vec2(m_body->GetMass()* moveSpeed, 0));

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

//    b2DistanceJointDef jointDef;
//    jointDef.Initialize(m_bodyCircle1, m_bodyCircle2, m_bodyCircle1->GetWorldCenter(), m_bodyCircle2->GetWorldCenter());
//    jointDef.length = 100.0f;
//    jointDef.collideConnected = true;
//    m_joint = dynamic_cast<b2WheelJoint *>(world->CreateJoint(&jointDef));
//    m_joint->SetUserData(this);

    b2RevoluteJointDef revoluteJointDef1;
    b2RevoluteJointDef revoluteJointDef2;

    revoluteJointDef1.Initialize(m_bodyCircle1, m_body, m_bodyCircle1->GetWorldCenter());
    revoluteJointDef2.Initialize(m_bodyCircle2, m_body, m_bodyCircle2->GetWorldCenter());

    m_revoluteJoint1 = dynamic_cast<b2RevoluteJoint *>(world->CreateJoint(&revoluteJointDef1));
    m_revoluteJoint2 = dynamic_cast<b2RevoluteJoint *>(world->CreateJoint(&revoluteJointDef2));

    m_revoluteJoint1->SetUserData(this);
    m_revoluteJoint2->SetUserData(this);
}

//_________________________
bool UserCar::m_registerIt =
        FactoryObject<CarObjects>::registerIt("mustang", [](std::unique_ptr<b2World> &world,
                                                            const sf::Vector2f &position,
                                                            const float rotation) -> std::unique_ptr<CarObjects> {
            return std::make_unique<UserCar>(mustang, world, position, rotation, b2_dynamicBody, Collide);
        });

//____________________________________________________
b2Vec2 UserCar::keyToDirection(sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::Up:
            return RIGHT;
        case sf::Keyboard::Down:
            return LEFT;
        case sf::Keyboard::Space:
        case sf::Keyboard::Z:
            return {0, -1};
        default:
            return {0, 0};
    }
}

//_________________________________________
void UserCar::move(const sf::Event &event) {

    b2Vec2 dir = keyToDirection(event.key.code);

//    if (dir == b2Vec2(0, 0)) {
//        setCarAngle(event.key.code); // set car angle
//    } else {
        moveCar(dir); // move car
        updateDust(dir); // car dust animation
//    }
}

//__________________________________________
void UserCar::updateDust(const b2Vec2 &key) {
    if (m_lastDir != key) {
        m_showDust = true; // draw dust true
        if (key == RIGHT) {
            m_dustOffset = carDustForward;
        } else if (key == LEFT) {
            m_dustOffset = carDustBackward;
        }
        m_dust.update(getPosition(), m_dustOffset);
    }
    m_lastDir = key;
}

//____________________________________________________
void UserCar::setCarAngle(const sf::Keyboard::Key &key) {
    /*if (getCarOnGround())
        return;
    else*/ if (key == sf::Keyboard::Right) {
        m_carAngle += carAngle;
        m_body->SetTransform(m_body->GetPosition(), m_carAngle);
    } else if (key == sf::Keyboard::Left) {
        m_carAngle -= carAngle;
        m_body->SetTransform(m_body->GetPosition(), m_carAngle);
    }
//    setCarOnGround(false);
}

//______________________________________
void UserCar::moveCar(const b2Vec2 &dir) {
    auto vel = m_body->GetLinearVelocity();
    auto desireVel = 250.0f;
    auto velChange = desireVel - vel.x;
    float impulse = m_body->GetMass() * velChange;

    m_body->ApplyLinearImpulse(impulse / 3 * dir, m_bodyCircle1->GetWorldCenter(), true);
    m_body->ApplyLinearImpulse(impulse * dir, m_bodyCircle2->GetWorldCenter(), true);

    m_body->ApplyAngularImpulse(0.1f * m_body->GetInertia() * -m_body->GetAngularVelocity(), true);

    b2Vec2 currentForwardNormal = m_body->GetLinearVelocity();
    float currentForwardSpeed = currentForwardNormal.Normalize();
    float dragForceMagnitude = -2 * currentForwardSpeed;
    m_body->ApplyForce(dragForceMagnitude * currentForwardNormal, m_body->GetWorldCenter(), true);

//    m_bodyCircle1->ApplyForce(b2Vec2(300, 0), m_body->GetWorldCenter(), true);
//    if (dir == RIGHT) {
//        m_body->ApplyLinearImpulseToCenter(impulse * dir, true);
//        m_bodyCircle1->ApplyLinearImpulse(b2Vec2(impulse, 0), m_body->GetWorldCenter(), true);
//        m_body->ApplyLinearImpulse(b2Vec2(impulse, 0), m_body->GetWorldCenter(), true);
//        m_bodyCircle2->ApplyLinearImpulse(b2Vec2(impulse, 0), m_body->GetWorldCenter(), true);
//        m_bodyCircle2->ApplyLinearImpulseToCenter(impulse * dir, true);
//        m_body->ApplyLinearImpulseToCenter(impulse * dir, true);
//    }
//    if (dir == LEFT) {
//        m_body->ApplyLinearImpulse(impulse * dir, b2Vec2(m_bodyCircle2->GetWorldCenter()), true);
//        m_bodyCircle1->ApplyLinearImpulse((impulse * 2) * dir, b2Vec2(m_body->GetWorldCenter()), true);
//    }
}

//_________________________________________
void UserCar::draw(sf::RenderWindow &window) {
    window.draw(m_sprite);
    drawDust(window);
    drawHealthBar(window);
    drawExplosion(window);
    drawCarPlace(window);
}

//_______________________________________________
void UserCar::drawDust(sf::RenderWindow &window) {
    if (m_showDust && m_dust.getAnimationIndex()) {
        m_dust.update(getPosition(), m_dustOffset);
        m_dust.draw(window);
    } else
        m_showDust = false;
}

//______________________________
float UserCar::getCarZoomView() {
    if (m_body->GetMass() * moveSpeed * m_carTimeDir.getElapsedTime().asSeconds() > 1.99818e+07) {
        m_carZoomView == 0.5f ? m_carZoomView -= 0.01f : m_carZoomView = 0.5;
    }
    return m_carZoomView = 0.6f;
}