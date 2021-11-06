//
// Created by vuniverse on 10/7/21.
//

#include "Animation.h"


Animation::Animation(const std::vector<std::string>& init_list, sf::Sprite& sprite_p):
        m_frames_list(init_list.size()),
        m_sprite{sprite_p}
{
    auto initListReader = init_list.cbegin();
    for( auto frame : m_frames_list ){
        if(initListReader == init_list.cend() ){
            throw std::out_of_range("Animation: init_list - data race only");
        }
        else if(!frame.loadFromFile(*initListReader))
            throw std::runtime_error("Cant find resources");
        frame.setSmooth(true);
        initListReader++;
    }
}

Animation::Animation(transformator transform_funk, sf::Sprite& sprite_p):
        m_sprite{sprite_p},
        m_transform{transform_funk},
        m_frames_list(1)//costilation for .size empty check
{
    //m_frames_list[0] = *m_sprite.getTexture();
}

//Animation::Animation():
//        m_sprite(m_sprite),               //danger it very stupid action
//        m_transform{none_transformator},
//        m_frames_list(0)               //for .size empty check (no need, we have these in this->size())
//{
//}

Animation::Animation(const std::string& a_sheet, sf::Sprite& a_sprite_p, pixels a_size, frames a_count) : //x==y
        m_sprite{a_sprite_p},
        m_frames_list(a_count),
        m_transform{default_transformator}
{
    for (frames i = 0; i < a_count; i++) {
        m_frames_list[i] = generateTextureX(a_sheet, a_size, i);
        m_frames_list[i].setSmooth(true);
    }
    m_sprite.setTexture(m_frames_list[0]);
}

Animation::Animation(const std::string& a_sheet, sf::Sprite& a_sprite_p, pixels a_size_x, pixels a_size_y,
                     frames a_frames_per_line, frames a_count) : //x!=y
        m_sprite{a_sprite_p},
        m_frames_list(a_count),
        m_transform{default_transformator}
{
    for (frames i = 0; i < a_count; i++) {
        m_frames_list[i] = generateTextureXY(a_sheet, a_size_x, a_size_y,
                                     i % a_frames_per_line, i / a_frames_per_line);
        m_frames_list[i].setSmooth(true);
    }
    m_sprite.setTexture(m_frames_list[0]);
}

Animation::Animation(const Animation& other):
        m_frames_list(other.m_frames_list),
        m_sprite{other.m_sprite},
        m_transform{default_transformator}
{
}

Animation::Animation(const std::string& a_sheet, sf::Sprite& a_sprite_p,
                     pixels a_size, frames a_count, transformator custom_transformator) :
        m_sprite{a_sprite_p},
        m_frames_list(a_count),
        m_transform{custom_transformator}
{
    for (frames i = 0; i < a_count; i++) {
        m_frames_list[i] = generateTextureX(a_sheet, a_size, i);
        m_frames_list[i].setSmooth(true);
    }
    m_sprite.setTexture(m_frames_list[0]);
}

Animation &Animation::operator=(Animation&& other) noexcept
{
    m_frames_list = other.m_frames_list;
    m_sprite = other.m_sprite;
    m_transform = other.m_transform;
    return *this;
}


bool Animation::play(uint8_t speed, bool direction) {
    static auto i = m_frames_list.begin();
    while (speed > 0) {
        if (direction) {
            if (i == m_frames_list.begin()) {
                m_transform(m_sprite, *i);
                i = m_frames_list.end();
                return true;
            }
            --i;
            m_transform(m_sprite, *i);
            return false;
        } else {
            ++i;
            if (i == m_frames_list.end()) {
                i = m_frames_list.begin();
                m_transform(m_sprite, *i);
                return true;
            }
            m_transform(m_sprite, *i);
            return false;
        }
        --speed;
    }
}

sf::Texture Animation::generateTextureX(const std::string& texture, const pixels& size, const pixels& offset)//offset by number of frames
{
    sf::Texture texture_out;
    if (!texture_out.loadFromFile(texture,sf::IntRect(offset * size, 0, size, size)))
        throw std::runtime_error("Cant find resources");
    return texture_out;
}

sf::Texture Animation::generateTextureXY(const std::string& texture, const pixels& x, const pixels& y,
                                         const pixels& offset_x, const pixels& offset_y)//offset by number of frames
{
    sf::Texture texture_out;
    if (!texture_out.loadFromFile(texture,sf::IntRect(offset_x * x, offset_y * y, x, y)))
        throw std::runtime_error("Cant find resources");
    return texture_out;
}

void Animation::default_transformator(sf::Sprite& sprite_t, const sf::Texture& texture_T )
{
     sprite_t.setTexture(texture_T);
}
void Animation::none_transformator(sf::Sprite&, const sf::Texture&)
{
}

int Animation::size() const
{
    if (m_transform == none_transformator && m_frames_list.size() == 0) {
        return -1;
    }
    return m_frames_list.size();
}