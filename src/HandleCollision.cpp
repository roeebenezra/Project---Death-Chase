#include "HandleCollision.h"

HandleCollision::HandleCollision() {
//    initializeCollisionMap();
}

HandleCollision &HandleCollision::instance() {
    static auto collision = HandleCollision();
    return collision;
}

void HandleCollision::gameObjectGameObject(GameObject *ground,
                                           GameObject *userCar) {
//    std::cout << "gameObject with GameObject!\n";
}

void HandleCollision::userCarGround(GameObject *userCar,
                                    GameObject *ground) {
    // To get the actual types and use them:
    // UserCar& user = dynamic_cast<UserCar&>(userCar);
    // Ground&  ground1  = dynamic_cast<Ground&>(ground);
//    std::cout << "userCar on Ground!\n";
}

void HandleCollision::groundUserCar(GameObject *ground,
                                    GameObject *userCar) {
    userCarGround(userCar, ground);
}

void HandleCollision::computerCarGround(GameObject *computerCar,
                                        GameObject *ground) {
//    std::cout << "computerCar on Ground!\n";
}

void HandleCollision::groundComputerCar(GameObject *ground,
                                        GameObject *computerCar) {
    computerCarGround(computerCar, ground);
}

void HandleCollision::barrelGround(GameObject *computerCar,
                                   GameObject *ground) {
//    std::cout << "computerCar on Ground!\n";
}

void HandleCollision::groundBarrel(GameObject *ground,
                                   GameObject *computerCar) {
    barrelGround(computerCar, ground);
}

void HandleCollision::userCarComputerCar(GameObject *userCar,
                                         GameObject *computerCar) {
//    std::cout << "userCar with computerCar!\n";
}

void HandleCollision::computerCarUserCar(GameObject *computerCar,
                                         GameObject *userCar) {
    userCarComputerCar(userCar, computerCar);
}

HandleCollision::HitMap HandleCollision::initializeCollisionMap() {

    HitMap phm;
//    phm[Key(typeid(GameObject), typeid(GameObject))] = &HandleCollision::gameObjectGameObject;

    phm[Key(typeid(UserCar), typeid(ComputerCar))] = &HandleCollision::userCarComputerCar;
    phm[Key(typeid(ComputerCar), typeid(UserCar))] = &HandleCollision::computerCarUserCar;

    phm[Key(typeid(UserCar), typeid(Ground))] = &HandleCollision::userCarGround;
    phm[Key(typeid(Ground), typeid(UserCar))] = &HandleCollision::groundUserCar;

    phm[Key(typeid(ComputerCar), typeid(Ground))] = &HandleCollision::computerCarGround;
    phm[Key(typeid(Ground), typeid(ComputerCar))] = &HandleCollision::groundComputerCar;

    phm[Key(typeid(Barrel), typeid(Ground))] = &HandleCollision::barrelGround;
    phm[Key(typeid(Ground), typeid(Barrel))] = &HandleCollision::groundBarrel;
//    ....
    return phm;
}

void HandleCollision::processCollision(GameObject *object1, GameObject *object2)
{
    dynamic_cast<GameObject*> (object1);
    dynamic_cast<GameObject*> (object2);
    static HitMap collisionMap = initializeCollisionMap();
    auto mapEntry = collisionMap.find(Key(typeid(*object1), typeid(*object2)));
    if (mapEntry != collisionMap.end()) {
        auto func = mapEntry->second;
        (this->*(func))(object1, object2);
    }
//    else {
//        std::cout << "couldn't find function \n";
//        //throw CollisionException("Unknown collision of ", object1, object2);
//    }
}