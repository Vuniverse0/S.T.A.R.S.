//
// Created by vuniverse on 10/27/21.
//

#include "Entry.h"
#include "../core/Handler.h"


Entry::Entry(const std::string& a_string, float_t x_ratio, float_t y_ratio)
{
    if ( a_string != EMPTY ) {
        m_object_texture.loadFromFile( a_string );
        m_object_texture.setSmooth( true );
        m_sprite.setTexture( m_object_texture );
        m_sprite.scale( Handler::x_ratio * x_ratio, Handler::y_ratio * y_ratio );
    }
}

bool Entry::hide()//return true if state was changed
{
    if ( m_visibility ) m_visibility = false;
    else return false;
    return true;
}

bool Entry::show()//return true if state was changed
{
    if (m_visibility) return false;
    else m_visibility = true;
    return true;
}
sf::Sprite& Entry::sprite() { return m_sprite; }
void Entry::draw() const { if(m_visibility) Handler::window().draw( m_sprite );}

void Entry::handle(Event event) { };
