#pragma once

#include "StaticObject.h"
#include "FactoryObject.h"
#include "macros.h"

class Barrel : public StaticObject {

public:
    Barrel(const int);
    static bool m_registerIt;
};