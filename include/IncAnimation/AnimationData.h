#pragma once

#include "Direction.h"

#include <unordered_map>
#include <vector>

struct AnimationData
{
    using ListType = std::vector<sf::IntRect>;
    using DataType = std::unordered_map<Direction, ListType>;
    DataType m_data;
};

//_________
namespace {
    AnimationData CoinObject(const sf::Vector2i size1, const sf::Vector2i init, const sf::Vector2i mid) {
        const auto size = size1;
        const auto initSpace = init;
        const auto middleSpace = mid;

        auto coin = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]() {
            currentStart += middleSpace;
            currentStart.x += size.x;
            return currentStart;
        };

        coin.m_data[Direction::Right].emplace_back(currentStart, size);
        coin.m_data[Direction::Right].emplace_back(nextStart(), size);
        coin.m_data[Direction::Right].emplace_back(nextStart(), size);
        coin.m_data[Direction::Right].emplace_back(nextStart(), size);
        coin.m_data[Direction::Right].emplace_back(nextStart(), size);
        coin.m_data[Direction::Right].emplace_back(nextStart(), size);

        return coin;
    }

    AnimationData dustObject(const sf::Vector2i size1, const sf::Vector2i init, const sf::Vector2i mid) {
        const auto size = size1;
        const auto initSpace = init;
        const auto middleSpace = mid;

        auto dust = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]() {
            currentStart += middleSpace;
            currentStart.x += size.x;
            return currentStart;
        };

        dust.m_data[Direction::Right].emplace_back(currentStart, size);
        dust.m_data[Direction::Right].emplace_back(nextStart(), size);
        dust.m_data[Direction::Right].emplace_back(nextStart(), size);
        dust.m_data[Direction::Right].emplace_back(nextStart(), size);
        dust.m_data[Direction::Right].emplace_back(nextStart(), size);

        return dust;
    }

    AnimationData carHealthObject(const sf::Vector2i size1, const sf::Vector2i init, const sf::Vector2i mid) {
        const auto size = size1;
        const auto initSpace = init;
        const auto middleSpace = mid;

        auto carHealth = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]() {
            currentStart += middleSpace;
            currentStart.y += size.y;
            return currentStart;
        };

        carHealth.m_data[Direction::Right].emplace_back(currentStart, size);
        carHealth.m_data[Direction::Right].emplace_back(nextStart(), size);
        carHealth.m_data[Direction::Right].emplace_back(nextStart(), size);
        carHealth.m_data[Direction::Right].emplace_back(nextStart(), size);
        carHealth.m_data[Direction::Right].emplace_back(nextStart(), size);
        carHealth.m_data[Direction::Right].emplace_back(nextStart(), size);

        return carHealth;
    }

    AnimationData explosionObject(const sf::Vector2i size1, const sf::Vector2i init, const sf::Vector2i mid) {
        const auto size = size1;
        const auto initSpace = init;
        const auto middleSpace = mid;

        auto carHealth = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]() {
            currentStart += middleSpace;
            currentStart.y += size.y;
            return currentStart;
        };

        carHealth.m_data[Direction::Right].emplace_back(currentStart, size);
        carHealth.m_data[Direction::Right].emplace_back(nextStart(), size);
        carHealth.m_data[Direction::Right].emplace_back(nextStart(), size);
        carHealth.m_data[Direction::Right].emplace_back(nextStart(), size);
        carHealth.m_data[Direction::Right].emplace_back(nextStart(), size);
        carHealth.m_data[Direction::Right].emplace_back(nextStart(), size);
        carHealth.m_data[Direction::Right].emplace_back(nextStart(), size);
        carHealth.m_data[Direction::Right].emplace_back(nextStart(), size);
        carHealth.m_data[Direction::Right].emplace_back(nextStart(), size);
        carHealth.m_data[Direction::Right].emplace_back(nextStart(), size);

        return carHealth;
    }
}
