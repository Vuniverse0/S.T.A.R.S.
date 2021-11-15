//
// Created by vuniverse on 10/27/21.
//

#pragma once

#include "typedefs_and_globals.h"
#include "Animation.h"


class Entry {
protected:
    sf::Vector2f m_normal_scale;
    sf::Sprite m_sprite;
    sf::Texture* m_texture = nullptr;
    Animation m_animation;
    bool m_visibility{true};
public:
    Entry() = delete;
    Entry(cords a_x, cords a_y, const std::string& a_string,
          frames a_frames, pixels a_pixels, transformator a_transformator);
    Entry(cords a_x, cords a_y, const std::string& a_string, transformator a_transformator);
    virtual ~Entry();

    bool isVisible()const;
    virtual bool isAnimated()const;

    bool hide();
    bool show();

    virtual void move(cords x, cords y);//set position for m_sprite
    virtual void origin(cords x, cords y);//set origin for m_sprite

    virtual void draw(sf::RenderWindow& window)=0;//Draw to screen
    virtual void handle()=0;//Change properties
};


