//
// Created by vuniverse on 11/5/21.
//

#pragma once

#include "Entry.h"


class Orbit
{
private:
    bool m_visibility;
    sf::ConvexShape m_elips;
    double m_way;
public:
    Orbit() = delete;
    Orbit(cords a_x, cords a_y, cords radius, frames quality = 100);

    sf::Vector2f getWay(float speed = 1);

    bool isVisible()const;
    static bool isAnimated();

    bool hide();
    bool show();

    void move(cords x, cords y);
    void anchor(cords x, cords y);
    void draw(sf::RenderWindow&);

};