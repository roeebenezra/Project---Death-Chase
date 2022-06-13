target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
        "Controller.h"
        "Data.h"
        "macros.h"
        "HandleCollision.h"
        "MyContactListener.h"

        "IncBuildGame/FactoryObject.h"
        "IncBuildGame/Resources.h"
        "IncBuildGame/Map.h"

        "IncObjects/GameObject.h"
        "IncObjects/MovingObject.h"
        "IncObjects/UserCar.h"
        "IncObjects/ComputerCar.h"
        "IncObjects/StaticObject.h"
        "IncObjects/Box.h"
        "IncObjects/Barrel.h"
        "IncObjects/FinishLine.h"
        "IncObjects/Ground.h"
        "IncObjects/Water.h"

        "IncAnimation/Animation.h"
        "IncAnimation/AnimationData.h"
        "IncAnimation/AnimationObjects.h"
        "IncAnimation/Coin.h"
        "IncAnimation/Dust.h"
        "IncAnimation/Direction.h"
        "IncAnimation/Explosion.h"
        "IncAnimation/HealthBar.h"

        "IncMenus/ChooseVehicleMenu.h"
        "IncMenus/OpenMenu.h"
        "IncMenus/GameMenu.h"
        "IncMenus/PlayMenu.h"
        "IncMenus/Button.h"
        "IncMenus/InGameMenuButton.h"
        "IncMenus/PauseButton.h"
        "IncMenus/OpenMenuButton.h"
        "IncMenus/MusicButton.h")