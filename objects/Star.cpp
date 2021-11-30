//
// Created by vuniverse on 11/21/21.
//

#include "Star.h"
#include "../core/Handler.h"
#include "../core/Containers.h"
#include "../utility/random_body.h"
#include "../utility/typedefs_and_globals.h"


uint16_t Star::m_idGenerator = 0;

Star::Star(const Stars& type, Sets sets, const std::string &file, cords radius, uint8_t stars_count) :
    Entry(file, 600, 100, 100),
    m_object{Body::Star, static_cast<unsigned int>(type), sets, file, ++m_idGenerator},
    m_body{star_body()},
    m_orbit(radius + m_sprite.getGlobalBounds().width),
    last_x(m_orbit.getWay().x)
{
    m_sprite.scale(m_body.bsize, m_body.bsize);
    for (uint8_t i = 0; i < (binominal_int(0,5,(m_body.bsize>1.f)?0.9f:0.2f)); ++i) {
        m_planets.emplace_back(Planets::Dry, Sets{{},{}},
                "none.png", m_sprite.getGlobalBounds().width);
    }
    if (stars_count == 2) {
        m_stars.push_back(
                Star(m_orbit.quality()/stars_count, m_body, m_object, radius));
    }
    else if (stars_count == 3) {
        m_stars.push_back(
                Star(m_orbit.quality()/stars_count, m_body, m_object, radius));
        m_stars.push_back(
                Star(m_orbit.quality()/stars_count*2, m_body, m_object, radius));
    }
}
Star::Star(uint8_t stars_count, MetaDataBody body, MetaDataObject object, Orbit orbit):
    Entry(object.file, 600, 100, 100),//TODO Object.type replace to random type
    m_object{Body::Star,static_cast<unsigned int>(object.type.star),
             object.sets, object.file, ++m_idGenerator},
    m_body{.speed = body.speed, .bsize = star_body().bsize, .spin = body.spin},
    m_orbit(orbit),
    last_x(m_orbit.getWay(stars_count).x)            //Make offset orbit here!
{
    m_sprite.scale(m_body.bsize, m_body.bsize);
}


Star::Star(const MetaDataObject& object, MetaDataBody body, cords radius) :
    Entry(object.file, 600, 100, 100),
    m_object{object},
    m_body{body},
    m_orbit(radius + m_sprite.getGlobalBounds().width),
    last_x(m_orbit.getWay().x)
{
}

//Star::Star(const Star& star, const std::string& file){}

Star::~Star()
{

}

void Star::handle()
{

}

void Star::draw(sf::RenderWindow &window)
{

}