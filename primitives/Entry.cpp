#include "Entry.h"

Entry::Entry(const std::string& a_string, float_t x_ratio, float_t y_ratio)
{
    if ( a_string != EMPTY ) {
        m_object_texture.loadFromFile( a_string );
        m_object_texture.setSmooth( true );
        m_sprite.setTexture( m_object_texture );
        m_sprite.scale( ratio::x_ratio() * x_ratio, ratio::y_ratio() * y_ratio );
    }
}

Entry::Entry(const Entry& ent)
{
    m_object_texture = ent.m_object_texture;
    m_sprite = ent.m_sprite;
    m_sprite.setTexture( m_object_texture );
}

bool Entry::hide()//return true if state was changed
{
    if ( m_visibility ) m_visibility = false;
    else return false;
    return true;
}

bool Entry::show()//return true if state was changed
{
    if (!m_visibility) m_visibility = true;
    else return false;
    return true;
}

//sf::Sprite& Entry::sprite() { return m_sprite; }

void Entry::handle(const sf::Event& event) { }

void Entry::draw(sf::RenderTarget& target, const sf::RenderStates& states) const
{
    if(m_visibility) target.draw( m_sprite );
}

void Entry::move(float_t x, float_t y){m_sprite.move(x, y);}

sf::Rect<float> Entry::getGlobalBounds()const{return m_sprite.getGlobalBounds();}

const sf::Vector2f &Entry::getOrigin()const{return m_sprite.getOrigin();}

const sf::Vector2f &Entry::getScale()const{return m_sprite.getScale();}

const sf::Vector2f &Entry::getPosition()const{return m_sprite.getPosition();}

void Entry::setPosition(float_t x, float_t y){m_sprite.setPosition(x, y);}