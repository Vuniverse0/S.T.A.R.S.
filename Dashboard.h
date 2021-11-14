//
// Created by vuniverse on 11/14/21.
//
#pragma once

#include "typedefs_and_globals.h"
#include "Gui.h"

struct Corner{
    static sf::Vector2f LeftTop;
    static sf::Vector2f RightTop;
    static sf::Vector2f LeftBottom;
    static sf::Vector2f RightBottom;
};

class Dashboard : public Gui {

public:
    Dashboard(cords a_x, cords a_y, const std::string& a_string, transformator a_transformator);

    using Gui::isAnimated;

};