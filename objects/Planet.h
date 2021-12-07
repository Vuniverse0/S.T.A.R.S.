//
// Created by vuniverse on 11/21/21.
//

#pragma once
#include "Moon.h"


class Planet : public Entry {
    static uint16_t m_idGenerator;

    std::vector<Moon> m_moons;
    Orbit m_orbit;

    MetaDataObject m_object;
    MetaDataBody m_body;

    float_t last_x;
public:
    Planet(const Planets& type, Sets sets, const std::string& file, cords radius);
    Planet(const MetaDataObject&, MetaDataBody, cords);
    ~Planet() override;

    void handle() override ;
    void draw() override ;
};