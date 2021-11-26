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
    Moon(Moons type, Sets sets, const std::string& file, cords radius);
    ~Moon() override;

    void draw(sf::RenderWindow& window) override;
    void handle() override;
};