#include "StartMessage.h"

StartMessage::StartMessage() : m_drawMessage(true) {
    setMessage();
}

void StartMessage::setMessage() {
    auto message = startMessage;
    for (auto i = 0; i < amountOfMessages; ++i) {
        Sprite temp;
        temp.setTexture(Resources::instance().getTexture(message));
        temp.setPosition(messagePosition);
        m_messages.push_back(temp);
        message--;
    }
}

void StartMessage::drawMessage(sf::RenderWindow &window) {

    if (m_messages[m_messageIndex].getPosition().x > 0) {

        window.draw(m_messages[m_messageIndex]);

        if (m_messages[m_messageIndex].getPosition().x == 1700) {
            if (m_currIndex != m_messageIndex) {
                m_currIndex = m_messageIndex;
                m_messageClock.restart();
            }
            if (m_messageClock.getElapsedTime().asSeconds() < messageTime)
                return;
        }
        updateMessage(m_messages[m_messageIndex]);
    }

    if (m_messages[m_messageIndex].getPosition().x == 0)
        m_messageIndex++;
    if (m_messageIndex == amountOfMessages)
        m_drawMessage = false;
}

void StartMessage::updateMessage(sf::Sprite &message) {
    auto posX = message.getPosition().x - 10;
    message.setPosition(posX, message.getPosition().y);
}