#pragma once

#include "macros.h"
#include "IncObjects/GameObject.h"
#include "IncObjects/UserCar.h"
#include "IncObjects/ComputerCar.h"
#include "IncObjects/Ground.h"
#include "IncObjects/Water.h"
#include "IncAnimation/Coin.h"

class GameObject;

class HandleCollision {

public:
    static HandleCollision &instance();

    void processCollision(GameObject *, GameObject *);

private:
    HandleCollision(){}

    void operator=(const HandleCollision &) {}

    void userCarGround(GameObject *, GameObject *);

    void groundUserCar(GameObject *, GameObject *);

    void computerCarGround(GameObject *, GameObject *);

    void groundComputerCar(GameObject *, GameObject *);

    void userCarComputerCar(GameObject *, GameObject *);

    void computerCarUserCar(GameObject *, GameObject *);

    void computerCarComputerCar(GameObject *, GameObject *);

    void userCarCoin(GameObject *, GameObject *);

    void coinUserCar(GameObject *, GameObject *);

    void userCarWater(GameObject *, GameObject *);

    void waterUserCar(GameObject *, GameObject *);

    void computerCarWater(GameObject *, GameObject *);

    void waterComputerCar(GameObject *, GameObject *);

    using HitFunctionPtr = void (HandleCollision::*)(GameObject*, GameObject*);
    using Key = std::pair<std::type_index, std::type_index>;
    using HitMap = std::map<Key, HitFunctionPtr>;

    HitMap initializeCollisionMap();
};