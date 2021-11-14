//
// Created by vuniverse on 11/5/21.
//

#include "Orbit.h"
#include "Containers.h"

Orbit::Orbit(cords a_x, cords a_y, cords radius, frames quality) :
    m_x{a_x}, m_y{a_y},
    m_visibility{true}, m_way{0}
{
    m_elips.setPointCount(quality);
    for (unsigned short i = 0; i < quality; ++i) {
        float rad = (360.0f/quality * i) / (360.0f / F_PI / 2.0f);
        float x = std::cos(rad - 0.1f) * radius;
        float y = std::sin(rad + 0.3f) * radius * 0.6f;
        m_elips.setPoint(i, sf::Vector2f(x, y));
    }
    m_elips.setOutlineThickness(2);
    m_elips.setOutlineColor(sf::Color(88, 136, 255, 50));
    m_elips.setFillColor(sf::Color(0, 0, 0, 0));
    m_elips.setPosition(m_x, m_y);
    Containers::listOrbit.push_back(this);
}

void Orbit::draw(sf::RenderWindow& window)
{
    window.draw(m_elips);
}

bool Orbit::hide()
{//return true if state was changed
    if (m_visibility) {
        m_visibility = false;
        return true;
    }
    else {
        return false;
    }
}

bool Orbit::show()
{//return true if state was changed
    if (m_visibility) {
        return false;
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

bool Orbit::isAnimated()
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

sf::Vector2f Orbit::getWay(frames speed)
{
    m_way += speed;
    if(m_way == m_elips.getPointCount()){
        m_way = 0;
    }
    return{m_elips.getPoint(m_way).x + m_elips.getPosition().x,
           m_elips.getPoint(m_way).y + m_elips.getPosition().y};
}

