#include "HandleCollision.h"

HandleCollision &HandleCollision::instance() {
    static auto collision = HandleCollision();
    return collision;
}

void HandleCollision::userCarFinishLine(GameObject *userCar, GameObject *finishLine) {
    auto *user = dynamic_cast<UserCar *>(userCar);
    user->setCarAtFinishLine(true);
}

void HandleCollision::finishLineUserCar(GameObject *finishLine, GameObject *userCar) {
    userCarFinishLine(userCar, finishLine);
}

void HandleCollision::computerCarFinishLine(GameObject *computerCar, GameObject *floor) {
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
}

void HandleCollision::groundUserCar(GameObject *ground, GameObject *userCar) {
    userCarGround(userCar, ground);
}

void HandleCollision::computerCarGround(GameObject *computerCar, GameObject *ground) {
//    std::cout << "computerCar on Ground!\n";
}

void HandleCollision::groundComputerCar(GameObject *ground, GameObject *computerCar) {
    computerCarGround(computerCar, ground);
}

void HandleCollision::userCarComputerCar(GameObject *userCar, GameObject *computerCar) {
//    std::cout << "userCar with computerCar!\n";
}

void HandleCollision::computerCarUserCar(GameObject *computerCar, GameObject *userCar) {
    userCarComputerCar(userCar, computerCar);
}


void HandleCollision::computerCarComputerCar(GameObject *computerCar1, GameObject *computerCar2) {
//    auto *computer1 = dynamic_cast<ComputerCar *>(computerCar1);
//    auto *computer2 = dynamic_cast<ComputerCar *>(computerCar2);
}

void HandleCollision::userCarCoin(GameObject *, GameObject *coin) {
    auto *coin1 = dynamic_cast<Coin *>(coin);
    coin1->setObjectDead(true);
}

void HandleCollision::coinUserCar(GameObject *coin, GameObject *userCar) {
    userCarCoin(userCar, coin);
}


void HandleCollision::userCarWater(GameObject *userCar, GameObject *water) {
    auto *user = dynamic_cast<UserCar *>(userCar);
    user->setCarInWater(true);
}

void HandleCollision::waterUserCar(GameObject *water, GameObject *userCar) {
    userCarWater(userCar, water);
}

void HandleCollision::computerCarWater(GameObject *computerCar, GameObject *water) {
    auto *computer = dynamic_cast<ComputerCar *>(computerCar);
    computer->setCarInWater(true);
}

void HandleCollision::waterComputerCar(GameObject *water, GameObject *computerCar) {
    computerCarWater(computerCar, water);
}

HandleCollision::HitMap HandleCollision::initializeCollisionMap() {

    HitMap phm;

    phm[Key(typeid(UserCar), typeid(ComputerCar))] = &HandleCollision::userCarComputerCar;
    phm[Key(typeid(ComputerCar), typeid(UserCar))] = &HandleCollision::computerCarUserCar;
    phm[Key(typeid(ComputerCar), typeid(ComputerCar))] = &HandleCollision::computerCarComputerCar;

    phm[Key(typeid(UserCar), typeid(FinishLine))] = &HandleCollision::userCarFinishLine;
    phm[Key(typeid(FinishLine), typeid(UserCar))] = &HandleCollision::finishLineUserCar;

    phm[Key(typeid(ComputerCar), typeid(FinishLine))] = &HandleCollision::computerCarFinishLine;
    phm[Key(typeid(FinishLine), typeid(ComputerCar))] = &HandleCollision::finishLineComputerCar;

    phm[Key(typeid(UserCar), typeid(Ground))] = &HandleCollision::userCarGround;
    phm[Key(typeid(Ground), typeid(UserCar))] = &HandleCollision::groundUserCar;

    phm[Key(typeid(ComputerCar), typeid(Ground))] = &HandleCollision::computerCarGround;
    phm[Key(typeid(Ground), typeid(ComputerCar))] = &HandleCollision::groundComputerCar;

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