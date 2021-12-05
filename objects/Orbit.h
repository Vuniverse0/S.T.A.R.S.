//
// Created by vuniverse on 11/5/21.
//

#pragma once

#include "../primitives/Entry.h"


class Orbit : public Entry
{
    friend Containers;
private:
    using Entry::m_visibility;
    sf::ConvexShape m_elips;
    double m_way{0};
public:
    static std::vector<Orbit*> m_all;
public:
    Orbit() = delete;
    Orbit(cords radius, frames quality = 1000);
    Orbit(cords radius, cords x, cords y, frames quality = 1000);
    ~Orbit() override;

    frames quality();
    sf::Vector2f getWay(double_t speed = 1, bool direction = false);

    using Entry::hide;
    using Entry::show;

    void move(cords x, cords y);
    void handle() override;
    void draw() final;
};