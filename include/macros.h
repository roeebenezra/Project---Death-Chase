#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <typeinfo>
#include <typeindex>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Resources.h"
#include "box2d/box2d.h"


using namespace sf;
using namespace std;

const string FileName = "map.txt";

const string FontFile = "FontFile.ttf";

const vector Textures = {"background.png", "truck.png", "redCar.png", "greenCar.png",
                         "ground_1.png", "ground_2.png", "ground_3.png", "ground_4.png",
                         "ground_5.png", "ground_8.png", "ground_9.png", "barrel.png",
                         "openMenu.png", "musicIcons.png"};

enum TextureRcs {
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
    OpenMenuBackground,
    musicIcons,
    TexturesCount
};

const vector Sounds = {"GameMenuSound.wav"};

const int User = 0;

enum SoundRcs {
    OpenSound,
    SoundsCount
};

enum Menus {
    OpenGameMenu,
    HowToPlayMenu,
    ChooseCarMenu,
    Play,
    InGameMenu,
    MenusCount
};
