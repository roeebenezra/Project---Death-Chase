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

const std::vector Textures = {"PlayBackground.png", "truck.png", "redCar.png", "greenCar.png",
                              "ground_1.png", "ground_2.png", "ground_3.png", "ground_4.png",
                              "ground_5.png", "ground_8.png", "ground_9.png", "barrel.png",
                              "coin.png", "icon.png", "dust.png", "box.png", "healthObjectBar.png",
                              "one.png", "two.png", "three.png", "four.png", "five.png", "six.png",
                              "seven.png", "explosion.png", "water.png", "finishLine.png",
                              "openMenu.png", "musicIcons.png", "Buttons.png", "OpenMenuButtons.png",
                              "HowToPlay.png", "PauseMenu.png"};

const vector Sounds{"MenuSound.wav", "PlaySound.wav", "Click.wav"};

enum SoundRcs {
    MenuSound,
    GameSound,
    Click,
    SoundsCount
};

const int carVelocity = 180;

const double carAngle = 0.05;

//animations time
const float dustTime = 0.06f;
const float coinTime = 0.2f;
const float healthTime = 0.6f;
const float explosionTime = 0.01f;

const sf::Vector2f carDustForward = {-150, 0};
const sf::Vector2f carDustBackward = {90, 0};

const sf::Vector2f healthBarOffset = {40, -80};
const sf::Vector2f explosionOffset = {0, -500};

const int carPlaceOffset = 150;

const sf::Vector2f regularScale = {1, 1};
const sf::Vector2f oppositeScale = {-1, -1};

const int User = 0;


const int MenuButtonHeight = 100;
const int MenuButtonWidth = 283;

const int SoundButtonHeight = 125;
const int MusicButtonWidth = 105;
const int clicksButtonWidth = 155;

const vector<Vector2f> OpenMenuMenuButtonPos{Vector2f{1100, 300},
                                             Vector2f{1100, 450},
                                             Vector2f{1100, 600}};

const vector<IntRect> OpenMenuButtonsIntRect{IntRect(0, 0, MenuButtonWidth, MenuButtonHeight),
                                             IntRect(0, MenuButtonHeight * 2, MenuButtonWidth, MenuButtonHeight),
                                             IntRect(0, MenuButtonHeight * 4, MenuButtonWidth, MenuButtonHeight),};

enum OpenMenuButtuns {
    OpenMenuPlay,
    OpenMenuOptions,
    OpenMenuExit,
    OpenMenuButtonsCount
};

const IntRect SoundButtonRect(0, 0, clicksButtonWidth, SoundButtonHeight);
const IntRect SoundButtonRect2(320, 0, MusicButtonWidth, SoundButtonHeight);

const int InGameMenuButtonHeight = 130;
const int InGameMenuButtonWidth = 140;

const vector<Vector2f> InGameMenuButtonPos{Vector2f{600, 450},
                                           Vector2f{750, 450},
                                           Vector2f{900, 450},
                                           Vector2f{1050, 450}};

const vector<IntRect> InGameButtonsIntRect{IntRect(0, 1135, InGameMenuButtonWidth, InGameMenuButtonHeight),
                                           IntRect(0, 1010, InGameMenuButtonWidth, InGameMenuButtonHeight),
                                           IntRect(0, 1280, InGameMenuButtonWidth, InGameMenuButtonHeight),
                                           IntRect(0, 1410, InGameMenuButtonWidth, InGameMenuButtonHeight)};


enum InGameButtuns {
    InGamePause,
    InGameMusic,
    InGameHome,
    InGamePlay,
    InGameButtonsCount
};

enum TextureRcs {
    PlayBackground,
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
    coin,
    icon,
    dust,
    box,
    healthBar,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    explosion,
    water,
    finishLine,
    OpenMenuBackground,
    musicIcons,
    Buttons,
    OpenMenuButtons,
    HowToPlay,
    InGameMenuBackground,
    TexturesCount
};

const int carPLaceStart = three; // by the amount of cars in the game

enum Menus {
    OpenGameMenu,
    Play,
    ChooseCarMenu,
    MenusCount
};

enum OpenMenuButtons {
    PlayButton = 1,
    OptionsButton,
    ExitButton,
};

enum groupIndex {
    Collide = 3,
    DontCollide = -3,
    GroundCollide = 1,
    SensorCollide = -9,
};

