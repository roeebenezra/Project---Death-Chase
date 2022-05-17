#include "IncObjects/Ground.h"

bool Ground::m_registerIt = FactoryObject<StaticObject>::registerIt("ground_1", []()-> std::unique_ptr<StaticObject> { return std::make_unique<Ground>(ground_1); });

Ground::Ground(const int name) : StaticObject(name){}