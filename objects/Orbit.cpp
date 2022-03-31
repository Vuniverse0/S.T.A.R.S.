//
// Created by vuniverse on 11/5/21.
//

#include "Orbit.h"
#include "../core/Handler.h"



Orbit::Orbit(cords radius, frames quality) : Entry(EMPTY)
{
    //std::cerr<<"Orbit SUCCESSFUL↵\n";
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
}

Orbit::Orbit(cords radius, sf::Vector2f cord, frames quality) : Orbit(radius, quality)
{
    m_elips.move(cord);
}

Orbit::~Orbit()
{
}

void Orbit::draw()//draw shape on window
{
    if(m_visibility)
        Handler::window().draw(m_elips);
}

void Orbit::move(cords a_x, cords a_y)//move for sprite
{
    m_elips.move(a_x, a_y);
}

sf::Vector2f Orbit::getWay(double_t speed, bool direction)//return cords for next step on orbit(center)
{
    m_way = direction ? (m_way - speed) : (m_way + speed);
    if (static_cast<size_t>(m_way) >= m_elips.getPointCount() || m_way < 0) {
        m_way = direction ? static_cast<double>(m_elips.getPointCount()-1) : 0;
    }
    //std::cout<<"POS "<<static_cast<size_t>(m_way)<<std::endl;
    return (m_elips.getPoint(static_cast<size_t>(m_way)) + m_elips.getPosition());
}

float_t Orbit::getSize()//return perspective
{
    if(static_cast<size_t>(m_way) > getPointToPath(2) )
        return 0.998;
    else
        return 1.002;
}

void Orbit::handle()
{
}

frames Orbit::quality()
{
    return (m_elips.getPointCount()-1);
}

void Orbit::move(sf::Vector2f vec)
{
    move(vec.x, vec.y);
}

Orbit::Orbit(const Orbit &orbit) : Entry(EMPTY)
{
    m_elips = orbit.m_elips;
    m_visibility = m_visibility;
}

size_t Orbit::getPointToPath(int path, int num)
{
    double d = 0;
    for (size_t i = 0; i < (m_elips.getPointCount()-1); ++i) {
        d += std::sqrt(std::pow(m_elips.getPoint(i).x-m_elips.getPoint(i+1).x, 2) + std::pow(m_elips.getPoint(i).y-m_elips.getPoint(i+1).y,2));
    }
    double chek = 0;
    d = ((d / path) * num);
    size_t i = 0;
    for (; i < (m_elips.getPointCount()-1) && chek < d; ++i) {
        chek += std::sqrt(std::pow(m_elips.getPoint(i).x-m_elips.getPoint(i+1).x, 2) + std::pow(m_elips.getPoint(i).y-m_elips.getPoint(i+1).y,2));
    }
    return i;
}
