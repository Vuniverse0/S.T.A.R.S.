//
// Created by vuniverse on 10/27/21.
//

#pragma once

#include "../utility/typedefs_and_globals.h"
#include "Animation.h"


class Entry {
protected:
    sf::Vector2f m_normal_scale;
    sf::Sprite m_sprite;
    Animation m_animation;
    bool m_visibility{true};
    sf::Texture* m_texture = nullptr;
public:
    Entry() = delete;
    Entry(const std::string& a_string,
          frames a_frames, pixels size_x, pixels size_y);
    Entry(const std::string& a_string,
          frames a_frames, pixels a_pixels);
    Entry(const std::string& a_string);
    virtual ~Entry();

    bool isVisible()const;
    bool hide();
    bool show();

    virtual void move(cords x, cords y);//set position for m_sprite
    virtual void origin(cords x, cords y);//set origin for m_sprite
    virtual void scale(float_t x, float_t y);
    virtual void draw(sf::RenderWindow& window)=0;//Draw to screen
    virtual void handle()=0;//Change properties
};


