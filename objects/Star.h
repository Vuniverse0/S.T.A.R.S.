//
// Created by vuniverse on 11/21/21.
//

#pragma once
#include "Planet.h"

class Star : public Entry  {
    friend Containers;
    static uint16_t m_idGenerator;

    Orbit m_orbit;

    MetaDataObject m_object;
    MetaDataBody m_body;

    float_t last_x;
    std::vector<Planet> m_planets;
    std::vector<Star> m_stars;
    static std::vector<Star*> m_all;
    Star(const uint8_t& stars_count, MetaDataBody body, const MetaDataObject& object, const Orbit& orbit);
public:
    Star(const Stars& type, Sets sets, const std::string& file, uint8_t stars_count = 1);
    Star(const MetaDataObject&, MetaDataBody);
    ~Star() override;

    void addStar(const MetaDataObject& object, const MetaDataBody& body);
    void addPlanet(const MetaDataObject& object, const MetaDataBody& body);

    void handle() override ;
    void handle(sf::Int32 time) ;
    void draw() override ;
};