//
// Created by vuniverse on 11/3/21.
//

#include "Gui.h"


Gui::Gui(cords a_x, cords a_y, const std::string& a_string,
         frames a_frames, pixels a_pixels, transformator a_transformator) :
         Entry( a_x, a_y, a_string,a_frames, a_pixels, a_transformator)
{
}
Gui::Gui(cords a_x, cords a_y, cords a_anchor_x, cords a_anchor_y, const std::string& a_string,
         frames a_frames, pixels a_pixels, transformator a_transformator) :
         Entry( a_x, a_y, a_anchor_x, a_anchor_y, a_string,a_frames, a_pixels, a_transformator)
{
}

Gui::Gui(cords a_x, cords a_y, const std::string& a_string, transformator a_transformator) :
         Entry(a_x, a_y, a_string, a_transformator)
{
}

bool Gui::isGui()const
{
    return true;
}