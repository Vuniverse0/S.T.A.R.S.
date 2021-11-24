//
// Created by vuniverse on 11/21/21.
//

#pragma once
#include "Moon.h"


class Planet : public Entry {
    static uint16_t m_idGenetaror;

    std::vector<Moon> m_moons;
    Orbit m_orbit;

    MetaDataObject m_object;
    MetaDataBody m_body;
public:
    Planet(Planets type, Sets sets, const std::string& file, cords radius);
    ~Planet();
    void handle() override ;
    void draw(sf::RenderWindow& window) override ;
};