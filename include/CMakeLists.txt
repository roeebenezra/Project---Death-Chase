target_include_directories (${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_sources (${CMAKE_PROJECT_NAME} PRIVATE  "Controller.h"
												"Data.h"
												"IncObjects/GameObject.h"
												
												"IncObjects/MovingObject.h"
												"IncObjects/UserCar.h"
												"IncObjects/ComputerCar.h"

												"IncObjects/StaticObject.h"
												"IncObjects/Box.h"
												"IncObjects/Barrel.h"

												"IncMenus/ChooseVehicleMenu.h"
												"IncMenus/OpenMenu.h"
												"IncMenus/GameMenu.h"
												"IncMenus/Button.h"
												"IncMenus/MusicButton.h"

												"IncBuildGame/Resources.h"
												"macros.h" )