//
// Created by vuniverse on 10/7/21.
//

#include "Animation.h"


Animation::Animation(const std::vector<std::string>& init_list, sf::Sprite& sprite_p):
        m_frames_list_(init_list.size()),
        m_sprite_{sprite_p}
{
    auto initListReader = init_list.cbegin();
    for( auto frame: m_frames_list_ ){
        if(initListReader == init_list.cend() ){

        }
        if(!frame.loadFromFile(*initListReader))
            throw std::runtime_error("Cant find resources");
        initListReader++;
    }
}

Animation::Animation(transformator transform_funk, sf::Sprite& sprite_p):
        m_sprite_{sprite_p},
        m_transform_{transform_funk},
        m_frames_list_(1)//costilation for .size empty check
{
}

Animation::Animation():
        m_sprite_(m_sprite_),//danger
        m_transform_{none_transformator_},
        m_frames_list_(0)//costilation for .size empty check
{
}

Animation::Animation(const std::string& sheet, sf::Sprite& sprite_p, pixels size, frames count):
        m_sprite_{sprite_p},
        m_frames_list_(count),
        m_transform_{default_tansformator_}
{
    for(frames i = 0; i<count; i++){
        m_frames_list_[i] = generateTextureX(sheet, size, i);
    }
    m_sprite_.setTexture(m_frames_list_[0]);
}

Animation::Animation(const Animation& other):
        m_frames_list_(other.m_frames_list_),
        m_sprite_{other.m_sprite_},
        m_transform_{default_tansformator_}
{
}

Animation::Animation(const std::string& sheet, sf::Sprite& sprite_p, pixels, frames count, transformator custom_transformator):
        m_sprite_{sprite_p},
        m_frames_list_(count),
        m_transform_{custom_transformator}
{

}

Animation::~Animation()
= default;

Animation &Animation::operator=(Animation&& other) noexcept
{
    m_frames_list_ = other.m_frames_list_;
    m_sprite_ = other.m_sprite_;
    m_transform_ = other.m_transform_;
    return *this;
}


bool Animation::play(int8_t speed, bool direction) {
    static auto i = m_frames_list_.begin();

    if(direction){
        if(i == m_frames_list_.begin()){
            m_transform_(m_sprite_, *i);
            i = m_frames_list_.end();
            return true;
        }
        i--;
        m_transform_(m_sprite_, *i);
        return false;
    }else{
        i++;
        if(i == m_frames_list_.end()){
            i = m_frames_list_.begin();
            m_transform_(m_sprite_, *i);
            return true;
        }
        m_transform_(m_sprite_, *i);
        return false;
    }
}

sf::Texture Animation::generateTextureX(const std::string& texture, pixels size, pixels offset)//offset by number of frames
{
    sf::Texture texture_out;
    if(!texture_out.loadFromFile(texture,sf::IntRect(offset * size, 0, size, size)))
        throw std::runtime_error("Cant find resources");
    return texture_out;
}

sf::Texture Animation::generateTextureXY(const std::string& texture, pixels x, pixels y, pixels offset_x, pixels offset_y)//offset by number of frames
{
    sf::Texture texture_out;
    if(!texture_out.loadFromFile(texture,sf::IntRect(offset_x * x, offset_y * y, x, y)))
        throw std::runtime_error("Cant find resources");
    return texture_out;
}

void Animation::default_tansformator_(sf::Sprite& sprite_t, const sf::Texture& texture_T )
{
     sprite_t.setTexture(texture_T);
}
void Animation::none_transformator_(sf::Sprite&, const sf::Texture&)
{
}

int Animation::size() const
{
    if(m_transform_ == none_transformator_){
        return -1;
    }
    return m_frames_list_.size();
}