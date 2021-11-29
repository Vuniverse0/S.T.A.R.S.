//
// Created by vuniverse on 11/5/21.
//

#pragma once

#include "../primitives/Entry.h"


class Orbit : private Entry
{
private:
    using Entry::m_visibility;
    sf::ConvexShape m_elips;
    double m_way{0};
public:
    Orbit() = delete;
    Orbit(cords radius, frames quality = 1000);
    Orbit(cords radius, cords x, cords y, frames quality = 1000);
    ~Orbit() override = default;

    sf::Vector2f getWay(double_t speed = 1, bool direction = false);

    using Entry::hide;
    using Entry::show;

    void move(cords x, cords y);
    void handle() override;
    void draw(sf::RenderWindow&) final;
};