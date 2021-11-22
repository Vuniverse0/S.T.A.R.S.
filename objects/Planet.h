//
// Created by vuniverse on 11/21/21.
//

#pragma once
#include "Orbit.h"
#include "../core/Metadata.h"

class Planet : public Entry {
    Orbit m_orbit;
    static uint16_t m_idGenetaror;
public:
    Planet(Metadata);
    ~Planet();
    void handle() override ;
    void draw(sf::RenderWindow& window) override ;
};