//
// Created by vuniverse on 11/3/21.
//

#include "Gui.h"


Gui::Gui(const std::string& a_string,
         frames a_frames, pixels a_pixels) :
         Entry(a_string,a_frames, a_pixels)
{
}

Gui::Gui(const std::string& a_string,
         frames a_frames, pixels size_x, pixels size_y) :
        Entry(a_string,a_frames, size_x, size_y)
{
}

Gui::Gui(const std::string& a_string) :
         Entry(a_string)
{
}

bool Gui::isGui()const
{
    return true;
}

sf::Texture *Gui::getAttach()
{
    return m_texture;
}
