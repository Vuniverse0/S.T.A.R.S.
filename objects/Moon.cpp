//
// Created by vuniverse on 11/24/21.
//

#include "Moon.h"
#include "../core/Handler.h"
#include "../core/Containers.h"
#include "../utility/random_body.h"
#include "../utility/typedefs_and_globals.h"


uint16_t Moon::m_idGenerator = 0;

Moon::Moon(Moons type, Sets sets, const std::string& file, cords radius) :
        Entry(file, 600,100,100),
        m_orbit(radius + m_sprite.getGlobalBounds().width),
        m_object{Body::Moon, static_cast<unsigned int>(type), sets, file, ++m_idGenerator},
        m_body(moon_body())
{
    m_orbit.hide();

}

void Moon::draw(sf::RenderWindow &window)
{
    m_sprite.setPosition(m_orbit.getWay(m_body.spin, m_body.direction));
    if (last_x > m_sprite.getPosition().x) {
        last_x = m_sprite.getPosition().x;
        std::cout<< "Change" << std::endl;
    }

}

void Moon::handle()
{

}

Moon::~Moon()
{

}
