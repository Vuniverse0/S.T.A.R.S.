#include "Moon.h"
#include "../primitives/Entry.h"
#include "../utility/random_body.h"


uint16_t Moon::m_idGenerator = 0;

Moon::Moon(const Moons& type, Sets sets, const std::string& file, cords radius, sf::Vector2f planet_anchor) :
    Entry(file, 600,100,100),
    m_orbit(radius, planet_anchor),
    m_object{Body::Moon,
             {static_cast<unsigned int>(type)},
             sets,
             file,
             ++m_idGenerator,
             "Noname"},
    m_body(moon_body()),
    last_x(m_orbit.getWay(random_int(1,999)).x)
{
    m_orbit.hide();
}

Moon::Moon(MetaDataObject object, MetaDataBody body, cords radius, sf::Vector2f planet_anchor) :
    Entry(object.file, 600, 100, 100),
    m_object{object},
    m_orbit(radius, planet_anchor),
    m_body{body},
    last_x(m_orbit.getWay(random_int(1,999)).x)
{
}

void Moon::handle()
{
    m_sprite.setPosition(m_orbit.getWay(m_body.speed, m_body.direction));
    m_animation.play(m_body.spin, m_body.spin_direction);
    /*if (last_x > m_sprite.getPosition().x) {
        last_x = m_sprite.getPosition().x;
        std::cout<< "Change" << std::endl;
    }*/
}

void Moon::draw()
{
    Handler::window().draw(m_sprite);
}

Moon::~Moon()
{
    m_all.erase(std::find(m_all.begin(),m_all.end(), this));
}
