//
// Created by vuniverse on 11/21/21.
//

#include "../core/Containers.h"
#include "Planet.h"


uint16_t Planet::m_idGenetaror = 0;

Planet::Planet(Planets type, Sets sets, const std::string &file, cords radius) :
    Entry(file, 600, 100, 100),
    m_object{Body::Planet, static_cast<unsigned int>(type), sets, file},
    m_orbit(radius),
    m_body{planet_body()}
{

}

Planet::~Planet()
{

}
void Planet::handle()
{

}

void Planet::draw(sf::RenderWindow &window)
{

}