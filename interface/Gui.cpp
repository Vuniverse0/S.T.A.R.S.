//
// Created by vuniverse on 11/3/21.
//

#include "Gui.h"


std::vector<Gui*> Gui::m_all{};

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
    m_all.push_back(this);
}

sf::Texture *Gui::getAttach()
{
    return m_texture;
}

Gui::~Gui()
{
    m_all.erase(std::find(m_all.begin(),m_all.end(), this));
}
