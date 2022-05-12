target_include_directories (${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_sources (${CMAKE_PROJECT_NAME} PRIVATE  "Controller.h"
												"Data.h"
												"GameObject.h"
												
												"MovingObject.h"
												"UserCar.h"
												"ComputerCar.h"

												"StaticObject.h"
												"Cone.h"
												"Barrel.h"

												"GameWindow.h"
												"ChooseCarWindow.h"
												"MenuWindow"

												"Resources.h"
												"macros.h")