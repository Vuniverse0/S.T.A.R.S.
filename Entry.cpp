//
// Created by vuniverse on 10/27/21.
//

#include "Entry.h"


Entry::Entry(cords a_x, cords a_y):
        m_visibility(false),
        m_x(a_x), m_y(a_y)
{
}

Entry::~Entry()
= default;

void Entry::move(cords a_x, cords a_y)
{
    m_x = a_x;
    m_y = a_y;
    m_sprite.setPosition(m_x, m_y);
}

bool Entry::hide() {
    if(m_visibility){
        m_visibility = false;
        return true;//return true if state was changed
    }else{
        return false;
    }
}

bool Entry::show() {
    if(m_visibility){
        return false;//return true if state was changed
    }else{
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




