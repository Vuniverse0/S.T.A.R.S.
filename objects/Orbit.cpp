//
// Created by vuniverse on 11/5/21.
//

#include "../core/Containers.h"
#include "Orbit.h"


Orbit::Orbit(cords radius, frames quality) : Entry(EMPTY)
{
    m_elips.setPointCount(quality);
    for (unsigned short i = 0; i < quality; ++i) {
        float rad = (360.0f/quality * i) / (360.0f / F_PI / 2.0f);
        float x = std::cos(rad - 0.1f) * radius;
        float y = std::sin(rad + 0.3f) * radius * 0.6f;
        m_elips.setPoint(i, sf::Vector2f(x, y));
    }
    m_elips.setOutlineThickness(1);
    m_elips.setOutlineColor(sf::Color(88, 136, 255, 50));
    m_elips.setFillColor(sf::Color(0, 0, 0, 0));
    Containers::drawTrait(this);
}

Orbit::Orbit(cords radius, cords a_x, cords a_y, frames quality) : Entry(EMPTY)
{
    m_elips.setPointCount(quality);
    for (unsigned short i = 0; i < quality; ++i) {
        float rad = (360.0f/quality * i) / (360.0f / F_PI / 2.0f);
        float x = std::cos(rad - 0.1f) * radius;
        float y = std::sin(rad + 0.3f) * radius * 0.6f;
        m_elips.setPoint(i, sf::Vector2f(x, y));
    }
    m_elips.setOutlineThickness(1);
    m_elips.setOutlineColor(sf::Color(88, 136, 255, 50));
    m_elips.setFillColor(sf::Color(0, 0, 0, 0));
    Containers::drawTrait(this);
    move(a_x, a_y);
}

void Orbit::draw(sf::RenderWindow& window)//draw shape on window
{
    if(m_visibility)
        window.draw(m_elips);
}

void Orbit::move(cords a_x, cords a_y)//set position for shape
{
    m_elips.setPosition(a_x, a_y);
}

sf::Vector2f Orbit::getWay(double_t speed, bool direction)//return cords for next step on orbit(center)
{
    m_way = direction ? (m_way - speed) : (m_way + speed);
    if (static_cast<size_t>(m_way) >= m_elips.getPointCount() || m_way < 0) {
        m_way = direction ? static_cast<double>(m_elips.getPointCount()-1) : 0;
    }
    return (m_elips.getPoint(static_cast<size_t>(m_way)) + m_elips.getPosition());
}

void Orbit::handle()
{
}

frames Orbit::quality()
{
    return m_elips.getPointCount();
}
