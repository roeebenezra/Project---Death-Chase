#pragma once

#include "CarObjects.h"
#include "IncBuildGame/FactoryObject.h"

class ComputerCar : public CarObjects {

public:
    ComputerCar(const unsigned&,
                std::unique_ptr<b2World> &,
                const sf::Vector2f &,
                const float&,
                const b2BodyType&,
                const int16&);

    void move(const sf::Event &) override;

private:
    static bool m_registerRedCar;
    static bool m_registerYellowCar;
    static bool m_registerTruck;
    static bool m_registerHummer;
};