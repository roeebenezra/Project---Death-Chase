#include "IncObjects/Barrel.h"

Barrel::Barrel(const unsigned& name,
               std::unique_ptr<b2World> &world,
               const sf::Vector2f &position,
               const float& rotation,
               const b2BodyType& bodyType,
               const int16& group)
        : StaticObject(name, world, position, rotation, bodyType, group) {
    cout << "old barrel mass is " << m_body->GetMass() << "\n";
//    b2MassData* data;
//    m_body->GetMassData(data);
//    data->mass = 1;
//    data->center.Set(0, 0);
//    m_body->SetMassData(data);
    cout << "new barrel mass is " << m_body->GetMass() << "\n";
}

bool Barrel::m_registerIt =
        FactoryObject<StaticObject>::registerIt("barrel", [](std::unique_ptr<b2World> &world,
                                                             const sf::Vector2f &position,
                                                             const float rotation) -> std::unique_ptr<StaticObject> {
            return std::make_unique<Barrel>(barrel, world, position, rotation, b2_dynamicBody, Collide);
        });

