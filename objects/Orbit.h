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
    Orbit(cords radius, frames quality = 100);

    sf::Vector2f getWay(float speed = 1);

    bool isAnimated()const override ;

    void move(cords x, cords y) override ;
    void origin(cords a_x, cords a_y) override ;
    void handle() override;
    void draw(sf::RenderWindow&) final;
};