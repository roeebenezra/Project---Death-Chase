#pragma once

#include "macros.h"
#include "IncObjects/GameObject.h"
#include "IncObjects/MovingObject.h"
#include "IncObjects/StaticObject.h"
#include "IncObjects/UserCar.h"
#include "IncObjects/ComputerCar.h"
#include "IncObjects/Ground.h"
#include "IncObjects/Barrel.h"

class FactoryObject {
public:
    template <typename FuncType>
    static std::unique_ptr<FuncType> createObject(const int);
};

template<typename FuncType>
std::unique_ptr<FuncType> FactoryObject::createObject(const int name) {
    return std::make_unique<FuncType>(name);
}