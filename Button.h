//
// Created by vuniverse on 11/2/21.
//

#pragma once

#include "typedefs_and_globals.h"
#include "Animation.h"
#include "Gui.h"
class Button : public Gui {
    Animation m_animation_;
    sf::Sprite m_sprite_;
    bool m_current_{false};
public:
    Button(cords, cords, sf::Sprite);
    ~Button() override;
    void checkClick (sf::Vector2f);
    bool isOnClick ();
    void draw(sf::RenderWindow&)override ;
};