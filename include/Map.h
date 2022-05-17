#pragma once

#include "macros.h"
#include "FactoryObject.h"
#include <fstream>

class Map {
public:
    Map();
    void readBoardFile();
    bool checkEndOfFile() const;
    void sendBoardKeysToObjects();
    void clearBoard();


private:
    std::ifstream m_mapFile;
    std::vector<std::string> m_level;
    std::vector<std::string> m_levelTime;
    std::vector<std::vector<std::string>> m_levels;
};
