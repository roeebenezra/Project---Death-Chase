#pragma once

#include "macros.h"
#include <map>
#include <memory>
#include "IncObjects/MovingObject.h"
#include "IncObjects/StaticObject.h"

template<typename T>
class FactoryObject {
public:
    using pFnc = std::unique_ptr<T>(*)(const sf::Vector2f &,
                                       const sf::Vector2f &);

    static std::unique_ptr<T> create(const std::string &,
                                     const sf::Vector2f &,
                                     const sf::Vector2f &);

    static bool registerIt(const std::string &, pFnc);

    bool checkIfNameInMap(const std::string &name) const { return FactoryObject::getMap().count(name) > 0; }

private:
    static auto &getMap() {
        static std::map<std::string, pFnc> m_map;
        return m_map;
    }
};

template<typename T>
std::unique_ptr<T> FactoryObject<T>::create(const std::string &name,
                                            const sf::Vector2f &position,
                                            const sf::Vector2f &scale) 
{
    auto it = FactoryObject::getMap().find(name);
    if (it == FactoryObject::getMap().end())
        return nullptr;
    return it->second(position, scale);
}

template<typename T>
bool FactoryObject<T>::registerIt(const std::string &name, pFnc f) 
{
    FactoryObject::getMap().emplace(name, f);
    return true;
}