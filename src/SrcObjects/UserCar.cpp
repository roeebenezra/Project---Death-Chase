#include "IncObjects/UserCar.h"

//_______________________
UserCar::UserCar(const unsigned& name,
                 std::unique_ptr<b2World> &world,
                 const sf::Vector2f &position,
                 const float& rotation,
                 const b2BodyType& bodyType,
                 const int16& group) :
        MovingObject(name, world, position, rotation, bodyType, group),
        m_dust(getPosition(), regularScale) {}

//__________________________
bool UserCar::m_registerIt =
        FactoryObject<MovingObject>::registerIt("mustang", [](std::unique_ptr<b2World> &world,
                                                              const sf::Vector2f &position,
                                                              const float rotation) -> std::unique_ptr<MovingObject> {
            return std::make_unique<UserCar>(mustang, world, position, rotation, b2_dynamicBody, Collide);
        });

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

void UserCar::moveCar(const b2Vec2 &dir) {

//    float impulse = m_body->GetMass() * moveSpeed * m_carTimeDir.getElapsedTime().asSeconds();
    float impulse = m_body->GetMass() * moveSpeed;
    cout << getPosition().y << "\n";
    m_body->ApplyLinearImpulse(impulse * dir, m_body->GetWorldCenter(), true);
}

//___________________________________________
void UserCar::draw(sf::RenderWindow &window) {
    window.draw(m_sprite);
    drawDust(window);
    drawHealthBar(window);
    drawExplosion(window);
    drawCarPlace(window);
}

void UserCar::drawDust(sf::RenderWindow &window) {
    if (m_showDust && m_dust.getAnimationIndex()) {
        m_dust.update(getPosition(), m_dustOffset);
        m_dust.draw(window);
    } else
        m_showDust = false;
}

float UserCar::getCarZoomView() {
    if (m_body->GetMass() * moveSpeed * m_carTimeDir.getElapsedTime().asSeconds() > 1.99818e+07) {
        m_carZoomView == 0.5f ? m_carZoomView -= 0.01f : m_carZoomView = 0.5;
    }
    return m_carZoomView=0.6f;
}

