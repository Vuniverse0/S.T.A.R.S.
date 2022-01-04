//
// Created by vuniverse on 10/27/21.
//

#include "Entry.h"
#include "../core/Handler.h"


std::vector<Entry*> Entry::m_all{};

Entry::Entry(const std::string &a_string, frames a_frames, pixels a_x, pixels a_y) :
    m_visibility(true),
    m_sprite{},
    m_animation(a_string, m_sprite, a_x, a_y, a_frames)
{
    m_sprite.scale(Handler::x_ratio, Handler::y_ratio);
    m_all.push_back(this);
}

Entry::Entry(const std::string& a_string, frames a_frames, pixels a_pixels) :
    m_visibility(true),
    m_sprite{},
    m_animation(a_string, m_sprite, a_pixels, a_frames)
{
    m_sprite.scale(Handler::x_ratio, Handler::x_ratio);
    m_all.push_back(this);
}

Entry::Entry(const std::string& a_string) :
        m_visibility(true),
        m_sprite{},
        m_object_texture{}
{
    m_texture = &m_object_texture;
    if (a_string != EMPTY) {
        m_texture->loadFromFile(a_string);
        m_texture->setSmooth(true);
        m_sprite.setTexture(*m_texture);
        m_sprite.scale(Handler::x_ratio, Handler::y_ratio);
    }
    m_all.push_back(this);
}

Entry::~Entry()
{
    m_all.erase(std::find(m_all.begin(),m_all.end(), this));
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

sf::Sprite& Entry::sprite()
{
    return m_sprite;
}

void Entry::setAnimation(Animation &anim)
{
    m_animation = anim;
}
