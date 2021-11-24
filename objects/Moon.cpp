//
// Created by vuniverse on 11/24/21.
//

#include "Moon.h"

Moon::Moon(Moons type, Sets sets, const std::string& file, cords radius) :
        Entry(file, 600,100,100),
        m_orbit(radius),
        m_object{Body::Moon, static_cast<unsigned int>(type), sets, file},
{
    m_orbit.hide();
}
