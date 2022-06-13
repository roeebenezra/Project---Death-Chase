#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <typeinfo>
#include <typeindex>
#include <memory>
#include <math.h>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "IncBuildGame/Resources.h"
#include "box2d/box2d.h"
#include "Utillities.h"

using namespace sf;
using namespace std;

const string FileName = "map.txt";

const string FontFile = "FontFile.ttf";

const std::vector Textures = {"PlayBackground.png", "truck.png", "redCar.png", "yellowCar.png",
                              "hummer.png", "mustang.png",
                              "ground_1.png", "ground_2.png", "ground_3.png", "ground_4.png",
                              "ground_5.png", "ground_8.png", "ground_9.png", "barrel.png",
                              "coin.png", "icon.png", "dust.png", "box.png", "healthObjectBar.png",
                              "one.png", "two.png", "three.png", "four.png", "five.png", "six.png",
                              "seven.png", "explosion.png", "water.png", "finishLine.png", "rock.png",
                              "rollerCoaster.png", "fence.png", "letsGo.png", "1.png", "2.png", "3.png",
                              "openMenu.png", "musicIcons.png", "Buttons.png", "OpenMenuButtons.png"};

const int User = 0;

const int AmountOfLevels = 3;

const std::string EndLevelMark = "EndLevel";

const vector Sounds = {"GameMenuSound.wav"};

const int MenuButtonHeight = 102;
const int MenuButtonWidth = 285;

const int SoundButtonHeight = 125;
const int MusicButtonWidth = 100;
const int clicksButtonWidth = 150;

const int carPLaceStart = five; // by the amount of cars in the game

const float carAngle = 0.05f;
const float moveSpeed = 300.f;
const b2Vec2 RIGHT = {1, 0};
const b2Vec2 LEFT = {-1, 0};

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

const int amountOfMessages = 4;
const int startMessage = messageThree;
const float messageTime = 0.5f;
const sf::Vector2f messagePosition = {4000, 600};