#pragma once
#include "MovingObject.h"
#include "StaticObject.h"
#include "macros.h"

class Data
{
public:
	Data();

private:
	std::vector<MovingObject> m_moving;
	std::vector<StaticObject> m_static;
};

Data::Data()
{
}

