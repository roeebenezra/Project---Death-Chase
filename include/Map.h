#pragma once

#include "macros.h"
#include "FactoryObject.h"

class Data;

class Map {

public:
    Map() {}

    void readMapFile(Data &);

private:
    using OpenFile = std::ifstream;

    OpenFile openFile();

    bool checkIfFileOpened(std::ifstream &);

    void sendObjectsFromMap(Data &, std::ifstream &);

};
