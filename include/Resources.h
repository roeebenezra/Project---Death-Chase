#pragma once
#include "macros.h"

class Resources
{
public:
	static Resources& instance();
	Resources(const Resources&) = delete;
	void operator=(const Resources&) = delete;

private:
	Resources();
	void loadResources()
};

Resources::Resources()
{
}

Resources::~Resources()
{
}