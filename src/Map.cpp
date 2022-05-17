#include "Map.h"
#include "Data.h"

//________________________________
void Map::readMapFile(Data& data) {
    std::ifstream file = openFile();
    if(!checkIfFileOpened(file))
        return;
    auto readMap = Map(file);
    sendObjectsFromMap(data, readMap);
}

//___________________________
Map::OpenFile Map::openFile() {
    std::ifstream file;
    file.open(fileName);
    return file;
}

//______________________________________________
bool Map::checkIfFileOpened(std::ifstream &file) {
    if (!file) {
        std::cout << "file didn't open\n";
        return false;
    }
    return true;
}

//_____________________________________________________
void Map::sendObjectsFromMap(Data& data, Map& readMap){

    std::string typeOfObject;
    while(!readMap.m_istr.eof())
    {
        readMap.m_istr >> typeOfObject;
        data.setObject(typeOfObject);
    }
}