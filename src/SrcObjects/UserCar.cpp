#include "IncObjects/UserCar.h"

//_______________________
UserCar::UserCar(unsigned name,
                 std::unique_ptr<b2World> &world,
                 const sf::Vector2f &position,
                 const float rotation,
                 b2BodyType bodyType,
                 int16 group) :
        MovingObject(name, world, position, rotation, bodyType, group),
        m_dust(getPosition(), regularScale) {}

//__________________________
bool UserCar::m_registerIt =
        FactoryObject<MovingObject>::registerIt("userCar", [](std::unique_ptr<b2World> &world,
                                                              const sf::Vector2f &position,
                                                              const float rotation) -> std::unique_ptr<MovingObject> {
            return std::make_unique<UserCar>(userCar, world, position, rotation, b2_dynamicBody, Collide);
        });

//_________________________________________
void UserCar::move(const sf::Event &event) {

    b2Vec2 dir = keyToDirection(event.key.code);

    if (dir == b2Vec2(0, 0))
        setCarAngle(event.key.code); // set car angle
    else {
        moveCar(dir); // move car
        updateDust(event.key.code); // car dust animation
    }
}

void UserCar::updateDust(const sf::Keyboard::Key &key) {
    if (m_lastDir != key) {
        m_showDust = true; // draw dust true
        if (key == sf::Keyboard::Up) {
            m_dustOffset = carDustForward;
        } else if (key == sf::Keyboard::Down) {
            m_dustOffset = carDustBackward;
        }
        m_dust.update(getPosition(), m_dustOffset);
    }
    m_lastDir = key;
}

//____________________________________________________
void UserCar::setCarAngle(const sf::Keyboard::Key &key) {
    /*if (m_carOnGround)
        return;
    else*/ if (key == sf::Keyboard::Right) {
        m_carAngle += carAngle;
        m_body->SetTransform(m_body->GetPosition(), static_cast<float>(m_carAngle));
    } else if (key == sf::Keyboard::Left) {
        m_carAngle -= carAngle;
        m_body->SetTransform(m_body->GetPosition(), static_cast<float>(m_carAngle));
    }
}

//______________________________________
void UserCar::moveCar(const b2Vec2 &dir) {
    float impulse = m_body->GetMass() * carVelocity;
    m_body->ApplyLinearImpulse(b2Vec2(impulse * dir.x, impulse * dir.y), m_body->GetWorldCenter(), true);
}

//___________________________________________
void UserCar::draw(sf::RenderWindow &window) {
    window.draw(m_sprite);

    if (m_showDust && m_dust.getAnimationIndex()) {
        m_dust.update(getPosition(), m_dustOffset);
        m_dust.draw(window);
    } else
        m_showDust = false;

    drawHealthBar(window);
    drawExplosion(window);
    drawCarPlace(window);
}