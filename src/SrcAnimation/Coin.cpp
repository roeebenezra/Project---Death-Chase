#include "IncAnimation/Coin.h"

Coin::Coin(int name,
           std::unique_ptr<b2World> &world,
           const sf::Vector2f &position,
           const float rotation,
           b2BodyType bodyType,
           int16 group)
        : StaticObject(name, world, position, rotation, bodyType, group),
          m_animation(Resources::instance().animationData(Resources::Coin),
                      Direction::Right, m_sprite, coin) {
    m_sprite.setPosition(position);

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