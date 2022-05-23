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

//____________________________________________________________
void Map::sendObjectsFromMap(Data &data, std::ifstream & file) {

    std::string typeOfObject;
    sf::Vector2f position;
    sf::Vector2f scale;
    while (!file.eof()) {
        file >> typeOfObject;
        file >> position.x >> position.y;
        file >> scale.x >> scale.y;
        data.setObject(typeOfObject, position, scale);
    }
}