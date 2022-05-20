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

const std::string fileName = "map.txt";
//const std::string fileName = "/Users/yaakovhaimoff/Desktop/school/year2/semester2/oop2/exercises/Project---Death-Chase/rcs/map.txt";

const std::string FontName = "FontFile.ttf";

const std::vector NAMES = {"background.png", "truck.png", "redCar.png", "greenCar.png",
                           "ground_1.png", "ground_2.png","ground_3.png","ground_4.png",
                           "ground_5.png", "ground_6.png", "ground_7.png", "ground_8.png",
                           "ground_9.png", "barrel.png"};

const int User = 0;

const float Scale = 100.f;

enum rcsNames {
    Background = 0,
    userCar,
    redCar,
    greenCar,
    ground_1,
    ground_2,
    ground_3,
    ground_4,
    ground_5,
    ground_6,
    ground_7,
    ground_8,
    ground_9,
    barrel
};