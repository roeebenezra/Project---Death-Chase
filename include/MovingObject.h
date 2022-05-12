#pragma once
#include "GameObject.h"

class MovingObject :public GameObject
{
public:
	MovingObject();
	~MovingObject();
	void move(){}

private:

};

MovingObject::MovingObject()
{
}

MovingObject::~MovingObject()
{
}