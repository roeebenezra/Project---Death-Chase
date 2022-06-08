#include "Resources.h"

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


//_________________________________
Resources::Resources() : m_data(Max) {
    loadResources();
    m_data[Coin] = CoinObject({50, 60}, {0, 0}, {20, 0});
    m_data[Dust] = dustObject({130, 86}, {0, 0}, {25, 0});
    m_data[HealthBar] = carHealthObject({113, 28}, {0, 0}, {0, 5});
    m_data[Explosion] = explosionObject({295, 245}, {0, 0}, {0, 6});
}

//______________________________
Resources &Resources::instance() {
    static auto resource = Resources();
    return resource;
}

//_____________________________
void Resources::loadResources() {
    if (!m_font.loadFromFile(FontName))
        std::cout << "fail to load font";

    for (int i = 0; i < NAMES.size(); i++) {
        sf::Texture texture;
        if (!texture.loadFromFile(NAMES[i]))
            std::cout << "fail to load " << i << " texture";
        m_texture.push_back(texture);
    }
}