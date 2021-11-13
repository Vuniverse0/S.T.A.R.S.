//
// Created by vuniverse on 10/27/21.
//

#pragma once

#include "typedefs_and_globals.h"
#include "Animation.h"


class Entry {
protected:
    sf::Vector2f m_normal_scale;
    cords m_x,m_y;
    sf::Sprite m_sprite;
    sf::Texture* m_texture = nullptr;
    Animation m_animation;
    bool m_visibility;
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

    void move(cords x, cords y);
    void anchor(cords x, cords y);

    virtual void draw(sf::RenderWindow& window)=0;
};


