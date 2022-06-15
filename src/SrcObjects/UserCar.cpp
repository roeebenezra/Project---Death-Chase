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
//    setB2d(world, bodyType, group);
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

    if (dir == b2Vec2(0, 0)) {
        setCarAngle(event.key.code); // set car angle
    } else {
        moveCar(dir); // move car
        updateDust(dir); // car dust animation
    }
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