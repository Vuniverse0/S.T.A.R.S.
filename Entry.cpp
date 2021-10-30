//
// Created by vuniverse on 10/27/21.
//

#include "Entry.h"


Entry::Entry(cords set_x, cords set_y):
        animation(),
        visibility(false),
        x(set_x),y(set_y)
{
}

Entry::~Entry()
= default;

void Entry::move(cords set_x, cords set_y)
{
    x = set_x;
    y = set_y;
    sprite.setPosition(x,y);
}

bool Entry::hide() {
    if(visibility){
        visibility = false;
        return true;//return true if state was changed
    }else{
        return false;
    }
}

bool Entry::show() {
    if(visibility){
        return false;//return true if state was changed
    }else{
        visibility = true;
        return true;
    }
}

bool Entry::is_visible()const
{
    return visibility;
}

bool Entry::is_animated() const {
    return animation.size() != 0;
}




