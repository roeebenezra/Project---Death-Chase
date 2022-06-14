#pragma once

#include "macros.h"

class Data;

class Map {

public:
    Map();

    void getObjectsFromMapLevel(Data &, const unsigned &);

    b2Vec2 getPlayerCheckPoint(const unsigned &,
                                     const float &) const;

private:
    using OpenFile = std::ifstream;

    OpenFile openFile();

    bool checkIfFileOpened(std::ifstream &);

    void readMapLevelsFromFile();

    void readFile(std::ifstream &);

    void setCheckPoints(std::ifstream &file, const unsigned &);

    std::vector<std::vector<std::string>> m_levelNames;
    std::vector<std::vector<sf::Vector2f>> m_levelPositions;
    std::vector<std::vector<float>> m_levelRotations;
    std::vector<std::vector<b2Vec2>> m_checkPoints;
};
