#pragma once

#include "macros.h"

class Data;

class Map {

public:
    Map() : m_levelNames(AmountOfLevels),
            m_levelPositions(AmountOfLevels),
            m_levelRotations(AmountOfLevels) {}

    void getObjectsFromFile(Data &, const unsigned&);

private:
    using OpenFile = std::ifstream;

    OpenFile openFile();

    bool checkIfFileOpened(std::ifstream &);

    void readMapFromFile(std::ifstream &);

    void sendObjectsFromMapLevel(Data &, const unsigned&);

    std::vector<std::vector<std::string>> m_levelNames;
    std::vector<std::vector<sf::Vector2f>> m_levelPositions;
    std::vector<std::vector<float>> m_levelRotations;
};
