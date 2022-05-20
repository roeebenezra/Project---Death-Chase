#include "IncObjects/Ground.h"

bool Ground::m_registerGround_1 = FactoryObject<StaticObject>::registerIt("ground_1",
                                                                          [](const sf::Vector2f &position,
                                                                             const sf::Vector2f &scale)
                                                                                  -> std::unique_ptr<StaticObject> {
                                                                              return std::make_unique<Ground>(ground_1,
                                                                                                              position,
                                                                                                              scale);
                                                                          });
bool Ground::m_registerGround_2 = FactoryObject<StaticObject>::registerIt("ground_2",
                                                                          [](const sf::Vector2f &position,
                                                                                         const sf::Vector2f &scale) -> std::unique_ptr<StaticObject> {
    return std::make_unique<Ground>(ground_2, position, scale);
});
bool Ground::m_registerGround_3 = FactoryObject<StaticObject>::registerIt("ground_3", [](const sf::Vector2f &position,
                                                                                         const sf::Vector2f &scale) -> std::unique_ptr<StaticObject> {
    return std::make_unique<Ground>(ground_3, position, scale);
});
bool Ground::m_registerGround_4 = FactoryObject<StaticObject>::registerIt("ground_4", [](const sf::Vector2f &position,
                                                                                         const sf::Vector2f &scale) -> std::unique_ptr<StaticObject> {
    return std::make_unique<Ground>(ground_4, position, scale);
});
bool Ground::m_registerGround_5 = FactoryObject<StaticObject>::registerIt("ground_5", [](const sf::Vector2f &position,
                                                                                         const sf::Vector2f &scale) -> std::unique_ptr<StaticObject> {
    return std::make_unique<Ground>(ground_5, position, scale);
});
bool Ground::m_registerGround_6 = FactoryObject<StaticObject>::registerIt("ground_6", [](const sf::Vector2f &position,
                                                                                         const sf::Vector2f &scale) -> std::unique_ptr<StaticObject> {
    return std::make_unique<Ground>(ground_6, position, scale);
});
bool Ground::m_registerGround_7 = FactoryObject<StaticObject>::registerIt("ground_7", [](const sf::Vector2f &position,
                                                                                         const sf::Vector2f &scale) -> std::unique_ptr<StaticObject> {
    return std::make_unique<Ground>(ground_7, position, scale);
});
bool Ground::m_registerGround_8 = FactoryObject<StaticObject>::registerIt("ground_8", [](const sf::Vector2f &position,
                                                                                         const sf::Vector2f &scale) -> std::unique_ptr<StaticObject> {
    return std::make_unique<Ground>(ground_8, position, scale);
});
bool Ground::m_registerGround_9 = FactoryObject<StaticObject>::registerIt("ground_9", [](const sf::Vector2f &position,
                                                                                         const sf::Vector2f &scale) -> std::unique_ptr<StaticObject> {
    return std::make_unique<Ground>(ground_9, position, scale);
});

Ground::Ground(const int name,
               const sf::Vector2f &position,
               const sf::Vector2f &scale)
               : StaticObject(name, position, scale) {}