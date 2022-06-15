#include "HandleCollision.h"

HandleCollision &HandleCollision::instance() {
    static auto collision = HandleCollision();
    return collision;
}

void HandleCollision::userCarFinishLine(GameObject *userCar, GameObject *) {
    auto *user = dynamic_cast<UserCar *>(userCar);
    user->setCarAtFinishLine(true);
}

void HandleCollision::finishLineUserCar(GameObject *finishLine, GameObject *userCar) {
    userCarFinishLine(userCar, finishLine);
}

void HandleCollision::computerCarFinishLine(GameObject *computerCar, GameObject *) {
    auto *computer = dynamic_cast<ComputerCar *>(computerCar);
    computer->setCarAtFinishLine(true);
}

void HandleCollision::finishLineComputerCar(GameObject *finishLine, GameObject *computerCar) {
    computerCarFinishLine(computerCar, finishLine);
}

void HandleCollision::userCarGround(GameObject *userCar, GameObject *ground) {
    auto *user = dynamic_cast<UserCar *>(userCar);
    user->setCarOnGround(true);
    user->setCarOnGroundAngle(ground->getAngle());
//    cout << "car on ground\n";
}

void HandleCollision::groundUserCar(GameObject *ground, GameObject *userCar) {
    userCarGround(userCar, ground);
}

void HandleCollision::userCarCoin(GameObject *userCar, GameObject *coin) {
    auto *coin1 = dynamic_cast<Coin *>(coin);
    coin1->setObjectDead(true);
    auto *user = dynamic_cast<UserCar *>(userCar);
    user->coinsCounter();
}

void HandleCollision::coinUserCar(GameObject *coin, GameObject *userCar) {
    userCarCoin(userCar, coin);
}


void HandleCollision::userCarWater(GameObject *userCar, GameObject *) {
    auto *user = dynamic_cast<UserCar *>(userCar);
    user->setCarInWater(true);
//    cout << "car in water\n";
}

void HandleCollision::waterUserCar(GameObject *water, GameObject *userCar) {
    userCarWater(userCar, water);
}

void HandleCollision::computerCarWater(GameObject *computerCar, GameObject *) {
    auto *computer = dynamic_cast<ComputerCar *>(computerCar);
    computer->setCarInWater(true);
}

void HandleCollision::waterComputerCar(GameObject *water, GameObject *computerCar) {
    computerCarWater(computerCar, water);
}

HandleCollision::HitMap HandleCollision::initializeCollisionMap() {

    HitMap phm;

    phm[Key(typeid(UserCar), typeid(FinishLine))] = &HandleCollision::userCarFinishLine;
    phm[Key(typeid(FinishLine), typeid(UserCar))] = &HandleCollision::finishLineUserCar;

    phm[Key(typeid(ComputerCar), typeid(FinishLine))] = &HandleCollision::computerCarFinishLine;
    phm[Key(typeid(FinishLine), typeid(ComputerCar))] = &HandleCollision::finishLineComputerCar;

    phm[Key(typeid(UserCar), typeid(Ground))] = &HandleCollision::userCarGround;
    phm[Key(typeid(Ground), typeid(UserCar))] = &HandleCollision::groundUserCar;

    phm[Key(typeid(UserCar), typeid(Coin))] = &HandleCollision::userCarCoin;
    phm[Key(typeid(Coin), typeid(UserCar))] = &HandleCollision::coinUserCar;

    phm[Key(typeid(UserCar), typeid(Water))] = &HandleCollision::userCarWater;
    phm[Key(typeid(Water), typeid(UserCar))] = &HandleCollision::waterUserCar;

    phm[Key(typeid(ComputerCar), typeid(Water))] = &HandleCollision::computerCarWater;
    phm[Key(typeid(Water), typeid(ComputerCar))] = &HandleCollision::waterComputerCar;

    return phm;
}

void HandleCollision::processCollision(GameObject *object1, GameObject *object2)
{
    static HitMap collisionMap = initializeCollisionMap();
    auto mapEntry = collisionMap.find(Key(typeid(*object1), typeid(*object2)));
    if (mapEntry != collisionMap.end()) {
        auto func = mapEntry->second;
        (this->*(func))(object1, object2);
    }
}