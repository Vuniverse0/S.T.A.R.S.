//
// Created by vuniverse on 10/27/21.
//

#pragma once

#include "typedefs_and_globals.h"
#include "Animation.h"


class Entry {
    cords x,y;
    sf::Sprite sprite;
    Animation animation;
    bool visibility;
public:
    Entry(cords, cords);
    virtual ~Entry();
    bool is_animated()const;
    bool is_visible()const;
    bool hide();
    bool show();
    void move(cords,cords);
    virtual bool is_gui()=0;
    virtual void draw(sf::Window&)=0;
};


