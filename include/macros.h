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
#include "IncBuildGame/Resources.h"
#include "Utillities.h"
#include "box2d/box2d.h"

using namespace sf;
using namespace std;

const string FileName = "map.txt";

const string FontFile = "FontFile.ttf";

const int FontSize = 150;
const unsigned CoinsSetIndex = 2;
const unsigned LevelsSetIndex = 6;

const std::vector<sf::Vector2f> PlayMenuTextPositions = {{-1100, 50},
                                                         {1900,  200}};

const std::vector Textures = {"mustang.png", "redCar.png", "hummer.png", "yellowCar.png",
                              "truck.png", "Tires.png", "PlayBackground.png", "PlayBackground2.png",
                              "ground_1.png", "ground_2.png", "ground_3.png", "ground_4.png",
                              "ground_5.png", "ground_8.png", "ground_9.png", "barrel.png",
                              "coin.png", "icon.png", "dust.png", "box.png", "healthObjectBar.png",
                              "one.png", "two.png", "three.png", "four.png", "five.png", "six.png",
                              "seven.png", "explosion.png", "water.png", "finishLine.png", "rock.png",
                              "rollerCoaster.png", "fence.png", "letsGo.png", "1.png", "2.png", "3.png",
                              "openMenu.png", "musicIcons.png", "Buttons.png",
                              "HowToPlay.png", "PauseMenu.png", "stone_1.png", "stone_2.png", "stone_3.png", "stone_4.png"};

const std::string Sounds[] = {"MenuSound.wav", "PlaySound.wav", "Click.wav"};

const double carAngle = 0.01;

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

const int MenuButtonHeight = 107;
const int MenuButtonWidth = 312;

const int SoundButtonHeight = 125;
const int MusicButtonWidth = 105;
const int clicksButtonWidth = 155;

const vector<Vector2f> OpenMenuMenuButtonPos{Vector2f{1100, 300},
                                             Vector2f{1100, 450},
                                             Vector2f{1100, 600}};

const vector<IntRect> OpenMenuButtonsIntRect{IntRect(0, 0, MenuButtonWidth, MenuButtonHeight),
                                             IntRect(0, MenuButtonHeight * 2, MenuButtonWidth, MenuButtonHeight),
                                             IntRect(0, MenuButtonHeight * 4, MenuButtonWidth, MenuButtonHeight),};


const IntRect SoundButtonRect(0, 0, clicksButtonWidth, SoundButtonHeight);
const IntRect SoundButtonRect2(320, 0, MusicButtonWidth, SoundButtonHeight);

const int InGameMenuButtonHeight = 135;
const int InGameMenuButtonWidth = 145;

const vector<Vector2f> InGameMenuButtonPos{Vector2f{600, 450},
                                           Vector2f{750, 450},
                                           Vector2f{900, 450},
                                           Vector2f{1050, 450},
                                           Vector2f{750, 300}};

const vector<IntRect> InGameButtonsIntRect{IntRect(0, 1210, InGameMenuButtonWidth, InGameMenuButtonHeight),
                                           IntRect(0, 1075, InGameMenuButtonWidth, InGameMenuButtonHeight),
                                           IntRect(0, 1360, InGameMenuButtonWidth, InGameMenuButtonHeight),
                                           IntRect(0, 1500, InGameMenuButtonWidth, InGameMenuButtonHeight),
                                           IntRect(0, 1650, InGameMenuButtonWidth, InGameMenuButtonHeight)};

const vector<IntRect> TireRects{IntRect(110, 0, 90, 90),
                                IntRect(230, 0, 90, 95),
                                IntRect(347, 0, 100, 100),
                                IntRect(0, 0, 90, 92),
                                IntRect(465, 0, 102, 101)};

const vector<std::pair<Vector2f ,Vector2f>> TireOffset {{{110,43},{130, 43}},{{140,55},{135,55}},
                                                        {{150,70},{140,70}},{{140,80},{140,80}},
                                                        {{110,70},{140,70}}};

const int AmountOfLevels = 3;

const std::string Objects = "Object";
const std::string CheckPointsMark  = "CheckPoint";
const std::string EndLevelMark = "EndLevel";

const int carPLaceStart = three; // by the amount of cars in the game

const b2Vec2 RIGHT = {1, 0};
const b2Vec2 LEFT = {-1, 0};

const int amountOfMessages = 4;
const int startMessage = messageThree;
const float messageTime = 0.5f;
const sf::Vector2f messagePosition = {4000, 600};
