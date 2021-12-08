//
// Created by vuniverse on 11/21/21.
//

#include "Planet.h"
#include "../core/Handler.h"
#include "../core/Containers.h"
#include "../utility/random_body.h"
#include "../utility/typedefs_and_globals.h"


uint16_t Planet::m_idGenerator = 0;

Planet::Planet(const Planets& type, Sets sets, const std::string &file, cords radius) :
    Entry(file, 600, 100, 100),
    m_object{Body::Planet, static_cast<unsigned int>(type), sets, file, ++m_idGenerator},
    m_body{planet_body()},
    m_orbit(radius + m_sprite.getGlobalBounds().width * 2.f),
    last_x(m_orbit.getWay(random_int(1,999)).x)
{ //TODO screen center for sun and planets orbit, multi sun state and one orbit move. Make orbit sections move
    m_sprite.scale(m_body.bsize, m_body.bsize);
    for (uint8_t i = 0; i < (binominal_int(0,5,(m_body.bsize>1.f)?0.9f:0.2f)); ++i) {
        m_moons.emplace_back(Moons::Dry, Sets{{},{}},
                "none.png", m_sprite.getGlobalBounds().width, center(&m_sprite));

    }
}

Planet::Planet(const MetaDataObject& object, MetaDataBody body, cords radius) :
    Entry(object.file, 600, 100, 100),
    m_object{object},
    m_orbit(radius),
    m_body{body},
    last_x(m_orbit.getWay(random_int(1,999)).x)
{

}

Planet::~Planet()
{

}

void Planet::handle()
{

}

void Planet::draw()
{

}