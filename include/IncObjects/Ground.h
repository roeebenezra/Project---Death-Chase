#pragma once

#include "StaticObject.h"
#include "FactoryObject.h"

class Ground : public StaticObject {

public:
    Ground(const int);
    static bool m_registerIt;
};