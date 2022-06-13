#include "IncObjects/Fence.h"

Fence::Fence(const unsigned& name,
             std::unique_ptr<b2World> &world,
             const sf::Vector2f &position,
             const float& rotation,
             const b2BodyType& bodyType,
             const int16& group)
        : StaticObject(name, world, position, rotation, bodyType, group) {
    cout << "old fence mass is " << m_body->GetMass() << "\n";
//    b2MassData* data;
//    m_body->GetMassData(data);
//    data->mass = 50;
//    data->center.Set(0, 0);
//    m_body->SetMassData(data);
    cout << "new fence mass is " << m_body->GetMass() << "\n";
}

bool Fence::m_registerIt =
        FactoryObject<StaticObject>::registerIt("fence", [](std::unique_ptr<b2World> &world,
                                                             const sf::Vector2f &position,
                                                             const float rotation) -> std::unique_ptr<StaticObject> {
            return std::make_unique<Fence>(fence, world, position, rotation, b2_dynamicBody, Collide);
        });

