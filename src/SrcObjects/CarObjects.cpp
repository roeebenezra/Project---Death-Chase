#include "IncObjects/CarObjects.h"

//______________________________________________
CarObjects::CarObjects(const unsigned& name,
                       std::unique_ptr<b2World> &world,
                       const sf::Vector2f &position,
                       const float& rotation,
                       const b2BodyType& bodyType,
                       const int16& group)
        : GameObject(name, world, position, rotation, bodyType, group),
          m_carHealth(getPosition(), oppositeScale), m_carExplosion(getPosition(), regularScale) {}

//______________________________________________________
void CarObjects::setB2d(std::unique_ptr<b2World> &world,
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
    if (!m_carExplosion.getAnimationIndex()){
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
}