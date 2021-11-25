//
// Created by vuniverse on 11/24/21.
//

#include "Moon.h"
#include "../core/Handler.h"
#include "../core/Containers.h"
#include "../utility/random_body.h"
#include "../utility/typedefs_and_globals.h"


Moon::Moon(Moons type, Sets sets, const std::string& file, cords radius) :
        Entry(file, 600,100,100),
        m_orbit(radius),
        m_object{Body::Moon, static_cast<unsigned int>(type), sets, file},
        m_body(moon_body())
{
    m_orbit.hide();
}

void Moon::draw(sf::RenderWindow &window)
{

}

void Moon::handle()
{

}

Moon::~Moon()
{

}
