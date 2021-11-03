//
// Created by vuniverse on 10/27/21.
//

#pragma once

#include "typedefs_and_globals.h"
#include "Animation.h"


class Entry {
protected:
    cords m_x,m_y;
    sf::Sprite m_sprite;
    Animation m_animation;
    bool m_visibility;
public:
    Entry(cords, cords);
    virtual ~Entry();
    bool isVisible()const;
    bool hide();
    bool show();
    void move(cords,cords);
    void anchor(cords,cords);
    virtual bool isAnimated()const;
    //virtual bool isGui()=0;
    virtual void draw(sf::RenderWindow&)=0;
};


