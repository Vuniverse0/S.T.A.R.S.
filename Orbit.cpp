//
// Created by vuniverse on 11/5/21.
//

#include "Orbit.h"


void Orbit::draw(sf::RenderWindow&)
{

}

/*Orbit::Orbit() {
    float radius_x = 315.0f;
    float radius_y = radius_x * 0.6f;
    float quality = 170.0f;
    sf::ConvexShape ellipse;
    ellipse.setPointCount(quality);

    for (unsigned short i =0; i < quality; ++i) {
        float rad = (360.0f/quality*i)/(360.0f/M_PI/2.0f);
        float x = cos(rad-0.1f)*radius_x;
        float y = sin(rad+0.3f)*radius_y;

        ellipse.setPoint(i,sf::Vector2f(x,y));
    }
}*/

Orbit::Orbit(cords a_x, cords a_y, cords radius) :
    m_x{a_x}, m_y{a_y},
    radius_x{radius},
    radius_y{radius * 0.6f},
    m_visibility{false}
{

}

bool Orbit::hide()
{
    if (m_visibility) {
        m_visibility = false;
        return true;//return true if state was changed
    }
    else {
        return false;
    }
}

bool Orbit::show()
{
    if (m_visibility) {
        return false;//return true if state was changed
    }
    else {
        m_visibility = true;
        return true;
    }
}

bool Orbit::isVisible()const
{
    return m_visibility;
}

bool Orbit::isAnimated() const
{
    return false;
}

void Orbit::move(cords a_x, cords a_y)
{
    m_x = a_x;
    m_y = a_y;
    m_elips.setPosition(m_x, m_y);
}

void Orbit::anchor(cords a_x, cords a_y)
{
    m_elips.setOrigin(a_x, a_y);
}

sf::Vector2f Orbit::getWay()
{
    return sf::Vector2f();
}

