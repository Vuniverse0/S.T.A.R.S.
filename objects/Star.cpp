//
// Created by vuniverse on 11/21/21.
//

#include "Star.h"
#include "../core/Handler.h"
#include "../utility/random_body.h"
#include "../utility/typedefs_and_globals.h"


uint16_t Star::m_idGenerator = 0;

//generate star
Star::Star(const Stars& type, Sets sets, const std::string &file, uint8_t stars_count) :
    Entry(file, 600, 200, 200),
    m_object{Body::Star,
             {static_cast<unsigned int>(type)},
             sets,
             file,
             ++m_idGenerator,
             "noname"},
    m_body{star_body()},
    m_orbit{m_sprite.getGlobalBounds().width * (m_body.bsize/(stars_count>1?1.5f:2.f)) * Handler::x_ratio, window_center(Handler::window())},
    last_x(stars_count>1?m_orbit.getWay(0).x:m_orbit.getWay(random_int(1,999)).x),
    m_planets{}
{
    //CONFIGURATION
    m_body.speed *= 10.f;
    m_body.spin *= 10.f;
    m_sprite.scale(m_body.bsize, m_body.bsize);

    m_sprite.setOrigin(local_center_basic(&m_sprite));
    m_orbit.hide();
    m_stars.reserve(3);
    if (stars_count == 1) {
        m_sprite.setPosition(window_center(Handler::window()));
    }
    else if (stars_count == 2) {
        m_stars.emplace_back(m_orbit.quality() / 2, m_body, m_object, m_orbit);
    }
    else if (stars_count == 3) {
        m_stars.emplace_back(m_orbit.getPointToPath(3)+50, m_body, m_object, m_orbit);
        m_stars.emplace_back(m_orbit.getPointToPath(3, 2)+50, m_body, m_object, m_orbit);
    }
    m_planets.reserve(2);
    //std::cout<< m_planets.capacity();
    for (uint8_t i = 0; i < m_planets.capacity(); ++i) {
        m_planets.emplace_back(Planets::Dry,
                               Sets{{},{}},
                               Loader::load(Planets::Dry),
                               ((float)(stars_count==3?2:stars_count)) * m_sprite.getGlobalBounds().width);
    }
}

//Multi star system constructor
Star::Star(const uint8_t& stars_offset, MetaDataBody body, const MetaDataObject& object, const Orbit& orbit):
    Entry(object.file, 600, 200, 200),//TODO Object.type replace to random type
    m_object{ Body::Star,
              object.type,
              object.sets,
              object.file,
              ++m_idGenerator,
              "Undefined" },
    m_body{body.speed,
           star_body().bsize < body.bsize ? star_body().bsize : body.bsize * 0.8f,
           body.spin,
           body.direction,
           body.spin_direction},
    m_orbit(orbit),
    last_x(m_orbit.getWay(stars_offset).x)            //Make offset orbit way here!
{
    m_orbit.hide();
    m_orbit.getWay(stars_offset,  m_body.direction);
    m_animation.play(stars_offset, m_body.spin_direction);
    m_sprite.scale(m_body.bsize, m_body.bsize);
    m_sprite.setOrigin(local_center_basic(&m_sprite));
}

//create from file
Star::Star(const MetaDataObject& object, const MetaDataBody& body) :
    Entry(object.file, 600, 200, 200),
    m_object{object},
    m_body{body},
    m_orbit(m_sprite.getGlobalBounds().width),
    last_x(m_orbit.getWay(0).x)
{
    m_orbit.hide();
    m_sprite.scale(m_body.bsize, m_body.bsize);
    m_sprite.setOrigin(local_center_basic(&m_sprite));
}

Star::~Star()
{
    /*
    for(auto& x: m_all){
        std::cout<< x << "\n";
    }
    std::cout<<std::endl;
    auto it = std::find(m_all.begin(),m_all.end(), this);
    if (it == m_all.end()) {
        std::cerr << "Star: fail to delete in m_all" << std::endl;
        throw std::runtime_error("~Star");
    }
    m_all.erase(it);*/
}

void Star::handle()
{}

void Star::m_handle()
{
    m_sprite.setPosition(m_orbit.getWay(m_body.speed, m_body.direction));
    auto size = m_orbit.getSize();
    m_sprite.scale(size, size);

    for ( auto& item : m_stars) {
        item.m_handle();
    }
    for ( auto& item : m_planets) {
        item.m_handle();
    }
}

void Star::handle(const sf::Int32& time)
{
    m_animation.play(m_body.spin * time, m_body.spin_direction);
    for ( auto& item : m_stars) {
        item.handle(time);
    }
    for ( auto& item : m_planets) {
        item.handle(time);
    }
}

void Star::draw(){}

void Star::m_draw()
{
    //TODO last_x recheck system write view
    Handler::window().draw(m_sprite);
    for ( auto& item : m_stars) {
        item.m_draw();
    }
    for ( auto& item : m_planets) {
        item.m_draw();
    }
}

void Star::addStar(const MetaDataObject& object, const MetaDataBody& body)
{
    if (m_stars.size() + 1 == 2) {
        m_stars.emplace_back(m_orbit.quality() / 2, body, object, m_orbit);
    }
    else if (m_stars.size() + 1 == 3) {
        m_stars.emplace_back(m_orbit.quality() / 3, body, object, m_orbit);
        m_stars.emplace_back((m_orbit.quality() / 3) * 2, body, object, m_orbit);
    }
}

void Star::addPlanet(const MetaDataObject &object, const MetaDataBody &body)
{
    static cords located = m_stars.size() * m_sprite.getGlobalBounds().width;
    m_planets.emplace_back(object, body, located + body.bsize);
}
