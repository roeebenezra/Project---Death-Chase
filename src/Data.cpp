#include "Data.h"

//___________
Data::Data() {
    m_moving.push_back(1);
}

//_________________________________________
void Data::moveData(const sf::Event &event) {
    for (auto &moving: m_moving)
        moving.move(event);
}

//___________________________________________
void Data::drawData(sf::RenderWindow &window) {
    for (auto &moving: m_moving)
        moving.draw(window);
}
