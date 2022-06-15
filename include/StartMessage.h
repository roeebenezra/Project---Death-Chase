#pragma once

#include "macros.h"
#include "IncBuildGame/Resources.h"

class StartMessage {

public:
    StartMessage();

    void drawMessage(sf::RenderWindow &);

    void setDrawMessage(const bool draw) { m_drawMessage = draw; }
    [[nodiscard]]
    bool getDrawMessage() const { return m_drawMessage; }

private:
    void setMessage();

    void updateMessage(sf::Sprite &);

    sf::Clock m_messageClock;
    std::vector<sf::Sprite> m_messages;
    bool m_drawMessage;
    unsigned int m_messageIndex = 0;
    int m_currIndex = -1;
};