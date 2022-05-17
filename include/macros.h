#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "box2d/box2d.h"

using namespace sf;
using namespace std;

static const float VIEW_HEIGHT = 900.0f;
static const float VIEW_WIDTH = 1200.0f;

const std::string FontName = "FontFile.ttf";

const std::vector NAMES = {"background.png", "truck.png", "redCar.png", "greenCar.png",
                           "ground_1.png", "barrel.png"};

const int User = 0;

enum rcsNames {
    Background = 0,
    userCar,
    redCar,
    greenCar,
    ground_1,
    barrel
};