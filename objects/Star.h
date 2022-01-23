//
// Created by vuniverse on 11/21/21.
//

#pragma once
#include "Planet.h"

class Star : public Entry  {
    static uint16_t m_idGenerator;

    MetaDataObject m_object;
    MetaDataBody m_body;

    Orbit m_orbit;

    float_t last_x;
    std::vector<Planet> m_planets;
    std::vector<Star> m_stars{};
public:
    Star(const uint8_t& stars_offset, MetaDataBody body, const MetaDataObject& object, const Orbit& orbit);
    Star(const Stars& type, Sets sets, const std::string& file, uint8_t stars_count = 1);
    Star(const MetaDataObject&, MetaDataBody);
    ~Star() override;

    void addStar(const MetaDataObject& object, const MetaDataBody& body);
    void addPlanet(const MetaDataObject& object, const MetaDataBody& body);

    void handle() override ;
    void handle(const sf::Int32& time) ;
    void m_handle();
    void m_draw();
    void draw() override ;
};