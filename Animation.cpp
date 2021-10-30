//
// Created by vuniverse on 10/7/21.
//

#include "Animation.h"


Animation::Animation(const std::vector<std::string>& init_list, sf::Sprite& sprite_p):
        frames_list(init_list.size()),
        sprite{sprite_p}
{
    auto initListReader = init_list.cbegin();
    for( auto frame: frames_list ){
        if(initListReader == init_list.cend() ){

        }
        frame.loadFromFile(*initListReader);
        initListReader++;
    }
}

Animation::Animation(transformator transform_funk, sf::Sprite& sprite_p):
    sprite{sprite_p},
    transform{transform_funk}
{
}

Animation::Animation(const std::string& sheet, sf::Sprite& sprite_p, pixels size, frames count):
    sprite{sprite_p},
    frames_list(count),
    transform{standart_tansformator}
{
    for(frames i = 0; i<count; i++){
        frames_list[i] = generateTextureX(sheet, size, i);
    }
    sprite.setTexture(frames_list[0]);
}

Animation::Animation(const Animation& other):
    frames_list(other.frames_list),
    sprite{other.sprite},
    transform{standart_tansformator}
{
}

Animation::Animation(const std::string& sheet, sf::Sprite& sprite_p, pixels, frames count, transformator custom_transformator):
    sprite{sprite_p},
    frames_list(count),
    transform{custom_transformator}
{

}


Animation &Animation::operator=(Animation&& other)
{
    frames_list = other.frames_list;
    sprite = other.sprite;
    transform = other.transform;
    return *this;
}


bool Animation::play(int8_t speed, bool direction) {
    static auto i = frames_list.begin();

    if(direction){
        if(i == frames_list.begin()){
            transform(sprite, *i);
            i = frames_list.end();
            return true;
        }
        i--;
        transform(sprite, *i);
        return false;
    }else{
        i++;
        if(i == frames_list.end()){
            i = frames_list.begin();
            transform(sprite, *i);
            return true;
        }
        transform(sprite, *i);
        return false;
    }
}

sf::Texture Animation::generateTextureX(const std::string& texture, pixels size, pixels offset)//offset by number of frames
{
    sf::Texture texture_out;
    texture_out.loadFromFile(texture,sf::IntRect(offset * size, 0, size, size));
    return texture_out;
}

sf::Texture Animation::generateTextureXY(const std::string& texture, pixels x, pixels y, pixels offset_x, pixels offset_y)//offset by number of frames
{
    sf::Texture texture_out;
    texture_out.loadFromFile(texture,sf::IntRect(offset_x * x, offset_y * y, x, y));
    return texture_out;
}

void Animation::standart_tansformator(sf::Sprite& sprite_t, const sf::Texture& texture_T )
{
     sprite_t.setTexture(texture_T);
}





