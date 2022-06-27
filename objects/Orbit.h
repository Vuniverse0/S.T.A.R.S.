//
// Created by vuniverse on 11/5/21.
//

#pragma once

#include "../primitives/Entry.h"


class Orbit : public Entry
{
private:
    using Entry::m_visibility;
    sf::ConvexShape m_elips;
    double m_way{0};
public:
    Orbit() = delete;
    explicit Orbit(cords radius, frames quality = 1000);
    Orbit(cords radius,  sf::Vector2f cord, frames quality = 1000);
    Orbit(const Orbit &orbit);
    ~Orbit() override;

    frames quality();
    sf::Vector2f getWay(double_t speed = 1, bool direction = false);
    float_t getSize();
    size_t getPointToPath(int path, int num = 1);

    using Entry::hide;
    using Entry::show;

    void move(cords x, cords y) override;
    void move(sf::Vector2f vec);
    void handle() override;
    void draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default) const override;
};