#include "Map.h"
#include "Data.h"

//________________________________
void Map::readMapFile(Data &data) {
    std::ifstream file = openFile();
    if (!checkIfFileOpened(file))
        return;
    sendObjectsFromMap(data, file);
}

//___________________________
Map::OpenFile Map::openFile() {
    std::ifstream file;
    file.open(FileName);
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

//____________________________________________________________
void Map::sendObjectsFromMap(Data &data, std::ifstream & file) {

    std::string typeOfObject = "1";
    sf::Vector2f position;
    float rotation;
    while (!file.eof()) {
        file >> typeOfObject;
        file >> position.x >> position.y;
        file >> rotation;
        data.setObject(typeOfObject, position, rotation);
    }
}