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

    Star(uint8_t stars_count, MetaDataBody body, MetaDataObject object, Orbit orbit);
public:
    Star() = delete;
    Star(const Stars& type, Sets sets, const std::string& file, cords radius, uint8_t stars_count = 1);
    Star(const MetaDataObject&, MetaDataBody, cords);
    //Star(const Star& star, const std::string& file);
    ~Star() override;

    void handle() override ;
    void draw(sf::RenderWindow& window) override ;
};