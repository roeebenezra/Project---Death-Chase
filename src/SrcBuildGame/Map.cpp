#include "IncBuildGame/Map.h"
#include "Data.h"

//_______________________________________
void Map::getObjectsFromFile(Data &data,
                             const unsigned& indexLevel) {
    std::ifstream file = openFile();
    if (!checkIfFileOpened(file))
        return;
    readMapFromFile(file);
    sendObjectsFromMapLevel(data, indexLevel);
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

//____________________________________________
void Map::readMapFromFile(std::ifstream &file) {

    unsigned index = 0;
    std::string typeOfObject;
    sf::Vector2f position;
    float rotation;

    while (!file.eof()) {
        file >> typeOfObject;
        if (typeOfObject == EndLevelMark) {
            index++;
            file >> typeOfObject;
        }
        if (index == AmountOfLevels)
            break;

        m_levelNames[index].push_back(typeOfObject);
        file >> position.x >> position.y;
        m_levelPositions[index].push_back(position);
        file >> rotation;
        m_levelRotations[index].push_back(rotation);
    }
    file.close();
}

//____________________________________________
void Map::sendObjectsFromMapLevel(Data & data,
                                  const unsigned& indexLevel) {
    for (unsigned i = 0; i < m_levelNames[indexLevel].size(); ++i)
        data.setObject(m_levelNames[indexLevel][i],
                       m_levelPositions[indexLevel][i],
                       m_levelRotations[indexLevel][i]);
}

//userCar 2500 1500 0
//ground_5 1000 1900 0
//ground_5 2900 1900 0
//ground_5 4800 1900 0
//ground_5 6700 1900 0
//ground_5 8600 1900 0
//ground_5 10500 1900 0
//ground_5 12400 1900 0
//ground_5 14300 1900 0
//ground_5 16200 1900 0
//ground_5 18100 1900 0
//ground_5 20000 1900 0
//ground_5 21900 1900 0
//ground_5 23800 1900 0
//ground_5 25700 1900 0
//ground_5 27600 1900 0
//ground_5 29500 1900 0
//ground_5 31400 1900 0