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
    Entry(cords, cords, const std::string&, frames, pixels, transformator);
    Entry(cords, cords, const std::string&, transformator);
    virtual ~Entry();

    bool isVisible()const;
    virtual bool isAnimated()const;

    bool hide();
    bool show();

    void move(cords,cords);
    void anchor(cords,cords);

    virtual void draw(sf::RenderWindow&)=0;
};


