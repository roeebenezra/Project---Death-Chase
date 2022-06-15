#pragma once

#include "macros.h"
#include "IncBuildGame/Resources.h"

class StartMessage {

public:
    StartMessage();

    void drawMessage(sf::RenderWindow &);

    bool getDrawMessage() const { return m_drawMessage; }

    void resetStartMessage();

private:
    void setMessage();

    void updateMessage(sf::Sprite &);

    sf::Clock m_messageClock;
    std::vector<sf::Sprite> m_messages;
    bool m_drawMessage = true;
    unsigned m_messageIndex = 0;
    int m_currIndex = -1;
};