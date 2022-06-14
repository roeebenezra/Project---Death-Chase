#include "IncBuildGame/Map.h"
#include "Data.h"

//_________
Map::Map() : m_levelNames(AmountOfLevels),
             m_levelPositions(AmountOfLevels),
             m_levelRotations(AmountOfLevels),
             m_checkPoints(AmountOfLevels) {
    readMapLevelsFromFile();
}

//____________________________
void Map::readMapLevelsFromFile() {
    std::ifstream file = openFile();
    if (!checkIfFileOpened(file))
        return;
    readFile(file);
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

//______________________________________
void Map::readFile(std::ifstream &file) {

    unsigned index = 0;
    std::string typeOfObject;
    sf::Vector2f position;
    float rotation;

    while (!file.eof()) {
        file >> typeOfObject;
        if (typeOfObject == CheckPointsMark) {
            setCheckPoints(file, index);
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

//___________________________________________
void Map::setCheckPoints(std::ifstream &file,
                         const unsigned &index) {
    b2Vec2 checkPointPosition;
    std::string checkPoint;
    file >> checkPoint;
    while (checkPoint != EndLevelMark) {
        file >> checkPointPosition.x >> checkPointPosition.y;
        m_checkPoints[index].push_back(checkPointPosition);
        file >> checkPoint;
    }
}

//____________________________________________
void Map::getObjectsFromMapLevel(Data &data,
                                  const unsigned &indexLevel) {
    for (unsigned i = 0; i < m_levelNames[indexLevel].size(); ++i)
        data.setObject(m_levelNames[indexLevel][i],
                       m_levelPositions[indexLevel][i],
                       m_levelRotations[indexLevel][i]);
}

//_______________________________________________________________
b2Vec2 Map::getPlayerCheckPoint(const unsigned &levelIndex,
                                      const float &playerPosition) const {
    int minDistanceToCheckPoint = std::numeric_limits<int>::max(),
    temp;
    unsigned indexOfCheckPointToReturn;
    for (unsigned i = 0; i <m_checkPoints[levelIndex].size(); ++i) {
        temp = static_cast<int>(abs(m_checkPoints[levelIndex][i].x - playerPosition));
        if ( temp < minDistanceToCheckPoint) {
            minDistanceToCheckPoint = temp;
            indexOfCheckPointToReturn = i;
        }
    }
    return m_checkPoints[levelIndex][indexOfCheckPointToReturn];
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