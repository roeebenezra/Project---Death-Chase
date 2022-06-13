#include "HandleCollision.h"

HandleCollision &HandleCollision::instance() {
    static auto collision = HandleCollision();
    return collision;
}

void HandleCollision::userCarRock(GameObject *, GameObject *) {
    cout << "user car rock\n";
}

void HandleCollision::rockUserCar(GameObject *rock, GameObject *userCar) {
    userCarRock(userCar, rock);
}

//void HandleCollision::userCarFloor(GameObject *userCar, GameObject *floor) {
//    cout << "userCar on floor\n";
//}
//
//void HandleCollision::floorUserCar(GameObject *floor, GameObject *userCar) {
//    userCarFloor(userCar, floor);
//}
//
//void HandleCollision::computerCarFloor(GameObject *computerCar, GameObject *floor) {
//    cout << "computerCar on floor\n";
//}
//
//void HandleCollision::floorComputerCar(GameObject *floor, GameObject *computerCar) {
//    computerCarFloor(floor, computerCar);
//}

void HandleCollision::userCarGround(GameObject *userCar, GameObject *ground) {
    UserCar *user = dynamic_cast<UserCar *>(userCar);
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
    auto *user = dynamic_cast<UserCar *>(userCar);
    auto *computer = dynamic_cast<ComputerCar *>(computerCar);
    user->setCarOnGround(true);
//    int temp;
//    if((user->getCarPlace() > computer->getCarPlace() && user->getPosition().x < computerCar->getPosition().x )||
//            (user->getCarPlace() < computer->getCarPlace() && user->getPosition().x > computerCar->getPosition().x)) {
//        temp = computer->getCarPlace();
//        computer->setCarPlace(user->getCarPlace());
//        user->setCarPlace(temp);
//    }
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

    phm[Key(typeid(UserCar), typeid(Rock))] = &HandleCollision::userCarRock;
    phm[Key(typeid(Rock), typeid(UserCar))] = &HandleCollision::rockUserCar;

//    phm[Key(typeid(UserCar), typeid(Floor))] = &HandleCollision::userCarFloor;
//    phm[Key(typeid(Floor), typeid(UserCar))] = &HandleCollision::floorUserCar;
//
//    phm[Key(typeid(ComputerCar), typeid(Floor))] = &HandleCollision::computerCarFloor;
//    phm[Key(typeid(Floor), typeid(ComputerCar))] = &HandleCollision::floorComputerCar;

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