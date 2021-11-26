//
// Created by vuniverse on 11/21/21.
//

#pragma once
#include "Planet.cpp"

class Star : public Entry  {
    static uint16_t m_idGenerator;

    Orbit m_orbit;

    MetaDataObject m_object;
    MetaDataBody m_body;

    float_t last_x;
public:
    Star(Star type, Sets sets, const std::string& file, cords radius);
    Star(MetaDataObject, MetaDataBody, cords);
    ~Star() override;

    void handle() override ;
    void draw(sf::RenderWindow& window) override ;
};