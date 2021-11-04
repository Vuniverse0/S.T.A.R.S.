//
// Created by vuniverse on 11/2/21.
//

#pragma once

#include "typedefs_and_globals.h"
#include "Animation.h"
#include "Gui.h"



class Button : public Gui {
    using Entry::m_x;
    using Entry::m_y;
    using Entry::m_sprite;
    using Entry::m_animation;
    using Entry::m_visibility;

    bool m_current{false};
public:
    Button(cords, cords, const std::string&, transformator);
    ~Button() override;

    void checkClick (sf::Vector2i);
    bool isOnClick ();
    bool isOnMouse(sf::Vector2i);
    void draw(sf::RenderWindow&)override ;

    using Entry::move;
    using Entry::anchor;
    using Gui::isGui;
};