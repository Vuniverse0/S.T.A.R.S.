#include "Animation.h"

Animation::Animation(const std::string& a_sheet, sf::Sprite& a_sprite,
        pixels a_size_x, pixels a_size_y, frames a_count) : //x!=y
        m_sprite{&a_sprite},
        m_count{a_count},
        m_size_x{a_size_x},
        m_size_y{a_size_y}
{
    if ( a_count == 0 ) {
        m_count = ( m_texture.getSize().x / m_size_x ) * ( m_texture.getSize().y / m_size_y );
    }
    m_texture.loadFromFile(a_sheet);
    m_texture.setSmooth(true);
    assert(m_texture.getSize().x / m_size_x >= 1);
    assert(m_texture.getSize().y / m_size_y >= 1);
    assert( ( m_texture.getSize().x / m_size_x ) * ( m_texture.getSize().y / m_size_y ) == m_count);
}


Animation& Animation::operator=(const Animation& other)
{
    if(this == &other)
        return *this;
    m_sprite = other.m_sprite;
    m_texture = other.m_texture;
    m_i = other.m_i;
    m_count = other.m_count;
    m_size_x = other.m_size_x;
    m_size_y = other.m_size_y;
    counter = other.counter;
    return *this;
}


bool Animation::play(float_t speed, bool direction)
{
    if ( !m_alt_texture ) {
        m_alt_texture = m_sprite->getTexture();
        m_sprite->setTexture(m_texture);
    }
    bool result = false;
    counter += speed;
    if (
        (direction
        ?( m_i == 0 )
        :( m_i == m_count ) )
       ){
        m_i = (direction ? m_count - (m_i - m_count): 0);
        result = true;
    }
    if ( counter >= 1.f ) {
        pixels x = m_texture.getSize().x / m_size_x;
        m_sprite->setTextureRect(sf::IntRect{
            ( (m_texture.getSize().y / m_size_y != 1) ? (m_i % x) : m_i ) * m_size_x,
            ( (m_texture.getSize().y / m_size_y != 1) ? (m_i / x) : 0 ) * m_size_y,
            m_size_x,
            m_size_y});
        m_i = direction ? m_i - static_cast<frames>(counter) : m_i + static_cast<frames>(counter);
        counter = 0.f;
    }
    return result;
}

bool Animation::stop( bool setAlt )
{
    if ( !m_alt_texture )
        return false;
    if ( setAlt )
        m_sprite->setTexture( *m_alt_texture );
    m_alt_texture = nullptr;
    return true;
}
