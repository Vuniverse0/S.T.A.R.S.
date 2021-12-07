//
// Created by vuniverse on 11/21/21.
//

#pragma once
#include "Planet.h"

class Star : public Entry  {
    static uint16_t m_idGenerator;

    Orbit m_orbit;

    MetaDataObject m_object;
    MetaDataBody m_body;

    float_t last_x;
    std::vector<Planet> m_planets;
    std::vector<Star> m_stars;

    Star(uint8_t stars_count, MetaDataBody body, const MetaDataObject& object, const Orbit& orbit);
public:
    Star() = delete;
    Star(const Stars& type, Sets sets, const std::string& file, uint8_t stars_count = 1);
    Star(const MetaDataObject&, MetaDataBody);
    void addStar(Star);
    //Star(const Star& star, const std::string& file);
    ~Star() override;

    void handle() override ;
    void draw() override ;
};