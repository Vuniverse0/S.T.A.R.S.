//
// Created by vuniverse on 11/21/21.
//

#include "Planet.h"
#include "../core/Handler.h"
#include "../utility/random_body.h"
#include "../utility/typedefs_and_globals.h"


uint16_t Planet::m_idGenerator = 0;

Planet::Planet(const Planets& type, Sets sets, const std::string &file, cords radius) :
    Entry(file, 600, 100, 100),
    m_object{Body::Planet,
             {static_cast<unsigned int>(type)},
             sets,
             file,
             ++m_idGenerator,
             "Noname"},
    m_body{planet_body()},
    m_orbit{radius + m_sprite.getGlobalBounds().width * 2.f, window_center(Handler::window())},
    last_x(m_orbit.getWay(random_int(1,999)).x)
{ //TODO screen center for sun and planets orbit, multi sun state and one orbit move. Make orbit sections move
    m_sprite.scale(m_body.bsize, m_body.bsize);
    m_sprite.setOrigin(local_center(&m_sprite));

    return;
    for (uint8_t i = 0; i < (binominal_int(0,5,(m_body.bsize>1.f)?0.9f:0.2f)); ++i) {
        m_moons.emplace_back(Moons::Dry, Sets{{},{}},
                Loader::load(Moons::Dry), m_sprite.getGlobalBounds().width, center(&m_sprite));

    }
}

Planet::Planet(const MetaDataObject& object, MetaDataBody body, cords radius) :
    Entry(object.file, 600, 100, 100),
    m_object{object},
    m_orbit{radius, window_center(Handler::window())},
    m_body{body},
    last_x(m_orbit.getWay(random_int(1,999)).x)
{
    m_sprite.setOrigin(local_center_basic(&m_sprite));

}

Planet::~Planet()
{
    //m_all.erase(std::find(m_all.begin(),m_all.end(), this));
}

void Planet::handle()
{
}

void Planet::handle(const sf::Int32& time) {
    m_animation.play(m_body.spin * time, m_body.spin_direction);
    auto size = m_orbit.getSize();
    m_sprite.scale(size, size);
}

void Planet::m_handle()
{
    m_sprite.setPosition(m_orbit.getWay(m_body.speed, m_body.direction));
    //m_animation.play(m_body.spin, m_body.spin_direction);
    for ( auto& item : m_moons) {
        item.handle();
    }
}

void Planet::draw()
{
}

void Planet::m_draw()
{
    Handler::window().draw(m_sprite);
    //for ( auto& item : m_moons) {
      //  item.draw();
    //}
}