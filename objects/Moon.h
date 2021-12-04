//
// Created by vuniverse on 11/24/21.
//

#pragma once
#include "Orbit.h"
#include "../core/Metadata.h"


class Moon : public Entry{
    static uint16_t m_idGenerator;

    Orbit m_orbit;

    MetaDataObject m_object;
    MetaDataBody m_body;

    float_t last_x;
public:
    Moon(const Moons& type, Sets sets, const std::string& file, cords radius, sf::Vector2f planet_anchor);
    Moon(MetaDataObject, MetaDataBody, cords, sf::Vector2f planet_anchor);
    ~Moon() override;

    void draw() override;
    void handle() override;
};