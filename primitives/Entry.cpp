//
// Created by vuniverse on 10/27/21.
//

#include "Entry.h"


Entry::Entry(const std::string &a_string, frames a_frames, pixels a_x, pixels a_y) {

}

Entry::Entry(const std::string& a_string, frames a_frames, pixels a_pixels) :
        m_visibility(false),
        m_sprite{},
        m_animation(a_string, m_sprite, a_pixels, a_frames)
{
}

Entry::Entry(const std::string& a_string) :
        m_visibility(false),
        m_sprite{}
{
    m_texture = new sf::Texture();
    m_texture->loadFromFile(a_string);
    m_texture->setSmooth(true);
    m_sprite.setTexture(*m_texture);
}

Entry::~Entry()
{
    delete m_texture;
}

void Entry::move(cords a_x, cords a_y)
{
    m_sprite.setPosition(a_x, a_y);
}

void Entry::origin(cords x, cords y)
{
    m_sprite.setOrigin(x, y);
}

bool Entry::hide()
{//return true if state was changed
    if (m_visibility) {
        m_visibility = false;
        return true;
    }
    else {
        return false;
    }
}

bool Entry::show()
{//return true if state was changed
    if (m_visibility) {
        return false;
    }
    else {
        m_visibility = true;
        return true;
    }
}

bool Entry::isVisible()const
{
    return m_visibility;
}