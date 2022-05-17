#include "IncObjects/Ground.h"

bool Ground::m_registerGround_1 = FactoryObject<StaticObject>::registerIt("ground_1", []()-> std::unique_ptr<StaticObject> { return std::make_unique<Ground>(ground_1); });
bool Ground::m_registerGround_2 = FactoryObject<StaticObject>::registerIt("ground_2", []()-> std::unique_ptr<StaticObject> { return std::make_unique<Ground>(ground_2); });
bool Ground::m_registerGround_3 = FactoryObject<StaticObject>::registerIt("ground_3", []()-> std::unique_ptr<StaticObject> { return std::make_unique<Ground>(ground_3); });
bool Ground::m_registerGround_4 = FactoryObject<StaticObject>::registerIt("ground_4", []()-> std::unique_ptr<StaticObject> { return std::make_unique<Ground>(ground_4); });
bool Ground::m_registerGround_5 = FactoryObject<StaticObject>::registerIt("ground_5", []()-> std::unique_ptr<StaticObject> { return std::make_unique<Ground>(ground_5); });
bool Ground::m_registerGround_6 = FactoryObject<StaticObject>::registerIt("ground_6", []()-> std::unique_ptr<StaticObject> { return std::make_unique<Ground>(ground_6); });
bool Ground::m_registerGround_7 = FactoryObject<StaticObject>::registerIt("ground_7", []()-> std::unique_ptr<StaticObject> { return std::make_unique<Ground>(ground_7); });
bool Ground::m_registerGround_8 = FactoryObject<StaticObject>::registerIt("ground_8", []()-> std::unique_ptr<StaticObject> { return std::make_unique<Ground>(ground_8); });
bool Ground::m_registerGround_9 = FactoryObject<StaticObject>::registerIt("ground_9", []()-> std::unique_ptr<StaticObject> { return std::make_unique<Ground>(ground_9); });

Ground::Ground(const int name) : StaticObject(name){}