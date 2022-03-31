#include "Animation.h"

Animation::Animation(const std::string& a_sheet, sf::Sprite& a_sprite_p,
        pixels a_size_x, pixels a_size_y, frames a_count) : //x!=y
        m_sprite{a_sprite_p},
        m_count{a_count},
        m_size_x{a_size_x}, m_size_y{a_size_y},
        m_xy{true}
{
    m_image.loadFromFile(a_sheet);
    m_texture.setSmooth(true);
    m_sprite.setTexture(generateTextureXY(0,0));
}

Animation::Animation(const Animation& other) :
        m_sprite{other.m_sprite},
        m_texture{other.m_texture},
        m_image{other.m_image},
        m_i{other.m_i}, m_count{other.m_count},
        m_size_x{other.m_size_x}, m_size_y{other.m_size_y},
        m_xy{other.m_xy}{}

Animation& Animation::operator=(const Animation& other)
{
    m_sprite = other.m_sprite;
    m_texture = other.m_texture;
    m_image = other.m_image;
    m_i = other.m_i;
    m_count = other.m_count;
    m_size_x = other.m_size_x;
    m_size_y = other.m_size_y;
    m_xy = other.m_xy;
    return *this;
}


bool Animation::play(float_t speed, bool direction)
{
    bool result = false;
    counter += speed;
    if ((direction ? m_i == 0 : m_i == m_count)) {
        m_i = (direction ? m_count - (m_i - m_count): 0);
        result = true;
    }
    if ( counter >= 1.f ) {
        if (m_xy) {
            auto n = m_image.getSize().x/m_size_x;
            m_sprite.setTexture(generateTextureXY(m_i % n,m_i/n));
        }
        else m_sprite.setTexture(generateTextureX(m_i));
        m_i = direction ? m_i - static_cast<frames>(counter) : m_i + static_cast<frames>(counter);
        counter = 0.f;
    }
    return result;
}

sf::Texture& Animation::generateTextureX(const pixels& offset)
{
    if (
        !m_texture.loadFromImage(m_image,
        sf::IntRect(offset * m_size_x, 0, m_size_x, m_size_x))
       )
        std::cerr << "Animation::generateTextureX - Cant find resources\n";
    return m_texture;
}

sf::Texture& Animation::generateTextureXY(const pixels& offset_x, const pixels& offset_y)
{
    if (
        !m_texture.loadFromImage(m_image,
        sf::IntRect(offset_x * m_size_x, offset_y * m_size_y, m_size_x, m_size_y))
       )
        std::cerr << "Animation::generateTextureXY - Cant find resources\n"
        << offset_x * m_size_x << '\n' << offset_x << "X" << m_size_x << '\n'
        << offset_y * m_size_y << '\n' << offset_y << "Y" << m_size_y << '\n';
    return m_texture;
}

Animation::Animation() : m_sprite(m_sprite), m_count{0}{}//stupid and danger
