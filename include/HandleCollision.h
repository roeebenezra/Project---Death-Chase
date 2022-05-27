#pragma once

#include "macros.h"
#include "HashHandler.h"
#include "IncObjects/GameObject.h"
#include "IncObjects/UserCar.h"
#include "IncObjects/ComputerCar.h"
#include "IncObjects/Ground.h"
#include "IncObjects/Barrel.h"

class GameObject;

class HandleCollision {

public:
    static HandleCollision &instance();

    void processCollision(GameObject *, GameObject *);

private:
    HandleCollision();

    void operator=(const HandleCollision &) {}

    void gameObjectGameObject(GameObject *, GameObject *);

    void userCarGround(GameObject *, GameObject *);

    void groundUserCar(GameObject *, GameObject *);

    void computerCarGround(GameObject *, GameObject *);

    void groundComputerCar(GameObject *, GameObject *);

    void userCarComputerCar(GameObject *, GameObject *);

    void computerCarUserCar(GameObject *, GameObject *);

    void barrelGround(GameObject *, GameObject *);

    void groundBarrel(GameObject *, GameObject *);

    using HitFunctionPtr = void (HandleCollision::*)(GameObject *, GameObject *);
    using Key = std::pair<std::type_index, std::type_index>;
    using HitMap = std::unordered_map<Key, HitFunctionPtr, PairKeysHash, KeyEqual>;

    HitMap initializeCollisionMap();

};

class CollisionException : public std::runtime_error {
public:
    CollisionException(const std::string &s, GameObject *a, GameObject *b)
            : std::runtime_error(
            std::string(s) + typeid(a).name() + " and " + typeid(b).name()) {}
};