//
// Created by vuniverse on 11/5/21.
//

#pragma once

#include "Entry.h"


class Orbit
{
private:
    cords m_x,m_y;
    bool m_visibility;
    float radius_x;
    float radius_y;
public:
    Orbit() = delete;
    Orbit(cords, cords, cords);

    sf::Vector2f getWay();

    bool isVisible()const;
    bool isAnimated()const;

    bool hide();
    bool show();

    void move(cords,cords);
    void anchor(cords,cords);

    virtual void draw(sf::RenderWindow&)=0;

};