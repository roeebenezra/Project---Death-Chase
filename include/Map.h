#pragma once

#include "macros.h"
#include "FactoryObject.h"
#include <fstream>

class Data;

class Map {
public:
    Map(std::istream& istream1) : m_istr(istream1){}
    void readMapFile(Data&);

private:
    using OpenFile = std::ifstream;

    OpenFile openFile();

    bool checkIfFileOpened(std::ifstream &);

    void sendObjectsFromMap(Data&, Map&);

    std::istream& m_istr;
};
