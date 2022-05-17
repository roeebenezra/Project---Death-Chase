#include "IncObjects/Barrel.h"

bool Barrel::m_registerIt = FactoryObject<StaticObject>::registerIt("barrel", []()-> std::unique_ptr<StaticObject> { return std::make_unique<Barrel>(barrel); });

Barrel::Barrel(const int name) : StaticObject(name){}