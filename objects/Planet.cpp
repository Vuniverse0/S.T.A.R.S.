//
// Created by vuniverse on 11/21/21.
//

#include "Planet.h"
#include "../core/Handler.h"
#include "../core/Containers.h"
#include "../utility/random_body.h"
#include "../utility/typedefs_and_globals.h"


uint16_t Planet::m_idGenerator = 0;

Planet::Planet(Planets type, Sets sets, const std::string &file, cords radius) :
    Entry(file, 600, 100, 100),
    m_object{Body::Planet, static_cast<unsigned int>(type), sets, file, ++m_idGenerator},
    m_orbit(radius + m_sprite.getGlobalBounds().width),
    m_body{planet_body()}
{
    m_sprite.setScale(m_body.bsize, m_body.bsize);
    m_sprite.scale(Handler::x_ratio, Handler::y_ratio);
    for (uint8_t i = 0; i < (binominal_int(0,5,(m_body.bsize>1.f)?0.9f:0.2f)); ++i) {
        m_moons.emplace_back(Moons::Dry, Sets{{},{}}, "none.png", m_sprite.getGlobalBounds().width);

    }
}

Planet::Planet(MetaDataObject object, MetaDataBody body, cords radius) :
    Entry(object.file, 600, 100, 100),
    m_object{object},
    m_orbit(radius),
    m_body{body}
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