//
// Created by vuniverse on 11/21/21.
//

#include "Star.h"
#include "../core/Handler.h"
#include "../core/Containers.h"
#include "../utility/random_body.h"
#include "../utility/typedefs_and_globals.h"


uint16_t Star::m_idGenerator = 0;

//generate star
Star::Star(const Stars& type, Sets sets, const std::string &file, uint8_t stars_count) :
    Entry(file, 600, 100, 100),
    m_object{Body::Star, static_cast<unsigned int>(type), sets, file, ++m_idGenerator},
    m_body{star_body()},
    m_orbit((stars_count+1)*m_sprite.getGlobalBounds().width),
    m_stars(),
    last_x(stars_count>1?m_orbit.getWay().x:m_orbit.getWay(random_int(1,999)).x)
{
    m_sprite.scale(m_body.bsize, m_body.bsize);
    for (uint8_t i = 0; i < (binominal_int(0,5,(m_body.bsize>1.f)?0.9f:0.2f)); ++i) {
        m_planets.emplace_back(Planets::Dry, Sets{{},{}},
                "none.png", m_sprite.getGlobalBounds().width);
    }
    if (stars_count == 2) {
        m_stars.push_back(
                Star(m_orbit.quality()/stars_count, m_body, m_object, m_orbit));
    }
    else if (stars_count == 3) {
        m_stars.push_back(
                Star(m_orbit.quality()/stars_count, m_body, m_object, m_orbit));
        m_stars.push_back(
                Star(m_orbit.quality()/stars_count*2, m_body, m_object, m_orbit));
    }
}

//Multi star system constructor
Star::Star(uint8_t stars_count, MetaDataBody body, const MetaDataObject& object, const Orbit& orbit):
    Entry(object.file, 600, 100, 100),//TODO Object.type replace to random type
    m_object{Body::Star,static_cast<unsigned int>(object.type.star),
             object.sets, object.file, ++m_idGenerator},
    m_body{.speed = body.speed, .bsize = star_body().bsize, .spin = body.spin},
    m_orbit(orbit),
    last_x(m_orbit.getWay(stars_count).x)            //Make offset orbit way here!
{
    m_sprite.scale(m_body.bsize, m_body.bsize);
}

//create from file
Star::Star(const MetaDataObject& object, MetaDataBody body) :
    Entry(object.file, 600, 100, 100),
    m_object{object},
    m_body{body},
    m_orbit(m_sprite.getGlobalBounds().width),
    m_stars(),
    last_x(m_orbit.getWay(random_int(1,999)).x)
{
}

Star::~Star()
= default;

void Star::handle()
{

}

void Star::draw()
{

}

void Star::addStar(Star star)
{
    m_stars.push_back(star);
}
