#pragma once

#include <string>
#include <vector>
#include <iostream>
#include<stdio.h>
#include <fstream>
#include <map>
#include <typeinfo>
#include <typeindex>
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "box2d/box2d.h"
#include <memory>

using namespace sf;
using namespace std;

static const float VIEW_HEIGHT = 900.0f;
static const float VIEW_WIDTH = 1200.0f;

const std::string fileName = "map.txt";

const std::string FontName = "FontFile.ttf";

const std::vector NAMES = {"background.png", "truck.png", "redCar.png", "greenCar.png",
                           "ground_1.png", "ground_2.png", "ground_3.png", "ground_4.png",
                           "ground_5.png", "ground_8.png", "ground_9.png", "barrel.png"};

const int User = 0;

const float Scale = 30.f;

enum rcsNames {
    Background,
    userCar,
    redCar,
    greenCar,
    ground_1,
    ground_2,
    ground_3,
    ground_4,
    ground_5,
    ground_8,
    ground_9,
    barrel,
};