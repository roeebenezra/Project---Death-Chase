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

//ground_6 1800 1300 1 1
//ground_7 1900 1300 1 1
//ground_8 2000 1300 1 1
//ground_9 2100 1300 1 1


//ground_2 0 900 3 1
//ground_3 9000 900 3 1
//ground_4 5000 2000 1 3
//ground_5 0 2000 3 1
//ground_2 20000 300 1 1.8
//ground_3 23000 300 1 1.8