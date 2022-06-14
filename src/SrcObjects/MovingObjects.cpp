#include "IncObjects/MovingObject.h"

//___________________________________________
MovingObject::MovingObject(const unsigned &name,
                           std::unique_ptr<b2World> &world,
                           const sf::Vector2f &position,
                           const float &rotation,
                           const b2BodyType &bodyType,
                           const int16 &group)
        : GameObject(name, world, position, rotation, bodyType, group),
          m_carHealth(getPosition(), oppositeScale), m_carExplosion(getPosition(), regularScale)
          {
              //setB2d(world,bodyType,group);
          }

//______________________________________________________
void MovingObject::setB2d(std::unique_ptr<b2World> &world,
                        b2BodyType bodyType,
                        int16 group) {

    b2BodyDef bodyDef; // BodyDef
    bodyDef.type = bodyType;
    bodyDef.angle = m_sprite.getRotation();
    bodyDef.position.Set(getPosition().x, getPosition().y);

    m_body = world->CreateBody(&bodyDef); // set Body to world

    b2PolygonShape BoxShape; // set BoxShape
    BoxShape.SetAsBox(getWidth() / 2, getHeight() / 2);

    b2FixtureDef fixtureDef; // FixtureDef
    fixtureDef.shape = &BoxShape;
    fixtureDef.density = 1;
    m_body->ResetMassData();
    fixtureDef.friction = 1;
    fixtureDef.filter.groupIndex = group;
    m_body->CreateFixture(&fixtureDef);
    m_body->SetUserData(this);
}
//______________________________
bool MovingObject::showHealthBar() {
    return (getCarOnGround() && getRotation() < 182 && getRotation() > 178 && m_carHealth.getAnimationIndex()) ||
           getCarInWater();
}

//________________________________________________________
void MovingObject::drawHealthBar(sf::RenderWindow &window) {
    if (showHealthBar()) {
        m_carHealth.update(getPosition(), healthBarOffset);
        m_carHealth.draw(window);
    } else
        setCarOnGround(false);
}

//________________________________________________________
void MovingObject::drawExplosion(sf::RenderWindow &window) {

    if (!m_carHealth.getAnimationIndex() /*&& m_carExplosion.getAnimationIndex()*/) {
        m_carExplosion.update(getPosition(), explosionOffset);
        m_carExplosion.draw(window);
    }
//    if (!m_carExplosion.getAnimationIndex())
//        setObjectDead(true);
}

//_______________________________________________________
void MovingObject::drawCarPlace(sf::RenderWindow &window) {
    Sprite carPLaceSprite;
    carPLaceSprite.setTexture(Resources::instance().getTexture(m_carPLace));
    carPLaceSprite.setPosition({getPosition().x - carPlaceOffset, getPosition().y - carPlaceOffset});
    window.draw(carPLaceSprite);
}