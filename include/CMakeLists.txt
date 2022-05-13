target_include_directories (${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_sources (${CMAKE_PROJECT_NAME} PRIVATE  "Controller.h"
												"Data.h"
												"IncObjects/GameObject.h"
												
												"IncObjects/MovingObject.h"
												"IncObjects/UserCar.h"
												"IncObjects/ComputerCar.h"

												"IncObjects/StaticObject.h"
												"IncObjects/Cone.h"
												"IncObjects/Barrel.h"

												"IncWindows/GameWindow.h"
												"IncWindows/ChooseVehicleWindow.h"
												"IncWindows/MenuWindow.h"
												"IncWindows/GameWindow.h"

												"Resources.h"
												"macros.h" )