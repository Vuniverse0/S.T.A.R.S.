//
// Created by vuniverse on 10/27/21.
//

#include "Entry.h"


Entry::Entry(cords a_x, cords a_y, const std::string& a_string,
        frames a_frames, pixels a_pixels, transformator a_transformator) :
        m_visibility(false),
        m_sprite{},
        m_animation(a_string, m_sprite, a_pixels, a_frames, a_transformator),
        m_x(a_x), m_y(a_y)
{
    m_sprite.setPosition(m_x, m_y);//    m_sprite.setOrigin(a_x, a_y);
}

Entry::Entry(cords a_x, cords a_y, const std::string& a_string, transformator a_transformator) :
        m_visibility(false),
        m_sprite{},
        m_animation(a_transformator, m_sprite),
        m_x(a_x), m_y(a_y)
{
    m_texture = new sf::Texture();
    m_texture->loadFromFile(a_string);
    m_texture->setSmooth(true);
    m_sprite.setTexture(*m_texture);
    m_sprite.setPosition(m_x, m_y);
}

Entry::~Entry()
{
    if ( m_texture != nullptr )
        delete m_texture;
}

void Entry::move(cords a_x, cords a_y)
{
    m_x = a_x;
    m_y = a_y;
    m_sprite.setPosition(m_x, m_y);
}

bool Entry::hide()
{
    if (m_visibility) {
        m_visibility = false;
        return true;//return true if state was changed
    }
    else {
        return false;
    }
}

bool Entry::show()
{
    if (m_visibility) {
        return false;//return true if state was changed
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

bool Entry::isAnimated() const
{
    return (m_animation.size() > 0);
}

void Entry::anchor(cords a_x, cords a_y)
{
    m_sprite.setOrigin(a_x, a_y);
}