//
// Created by vuniverse on 11/24/21.
//

#pragma once
#include "Orbit.h"
#include "../core/Core.h"
#include "../utility/random_body.h"
#include "../utility/typedefs_and_globals.h"

class Moon : public Entry{
    static uint16_t m_idGenetaror;

    Orbit m_orbit;

    MetaDataObject m_object;
    MetaDataBody m_body;
public:
    Moon(Moons type, Sets sets, const std::string& file, cords radius);
    ~Moon();
};