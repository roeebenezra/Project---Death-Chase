#include "IncObjects/CarObjects.h"

//______________________________________________
CarObjects::CarObjects(const unsigned& name,
                       std::unique_ptr<b2World> &world,
                       const sf::Vector2f &position,
                       const float& rotation,
                       const b2BodyType& bodyType,
                       const int16& group)
        : GameObject(name, world, position, rotation, bodyType, group),
          m_carHealth(getPosition(), oppositeScale), m_carExplosion(getPosition(), regularScale) {
//    cout << "old car mass is " << m_body->GetMass() << "\n";
    b2MassData* data;
    m_body->GetMassData(data);

    data->mass = 20000;
    data->center.Set(0, -m_sprite.getLocalBounds().height/2);
//    m_body->SetMassData(data);
//    cout << "new car mass is " << m_body->GetMass() << "\n";
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