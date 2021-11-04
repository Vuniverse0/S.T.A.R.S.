//
// Created by vuniverse on 11/2/21.
//

#pragma once

#include "typedefs_and_globals.h"
#include "Animation.h"
#include "Gui.h"



class Button : public Gui {
private:
    using Entry::m_normal_scale;
    using Entry::m_x;
    using Entry::m_y;
    using Entry::m_sprite;
    using Entry::m_animation;
    using Entry::m_visibility;
    union {
        struct {
            uint8_t m_current: 1;
            uint8_t m_mouse: 1;
            uint8_t f2: 1;
            uint8_t f3: 1;
            uint8_t f4: 1;
            uint8_t f5: 1;
            uint8_t f6: 1;
            uint8_t f7: 1;
        } m_flags;
        [[maybe_unused]] uint8_t null = 0;
    };
public:
    Button(cords, cords, const std::string&, transformator);
    ~Button() override;

    void checkClick (sf::Vector2i);
    void checkMouse (sf::Vector2i);

    void draw(sf::RenderWindow&)override;

    using Entry::move;
    using Entry::anchor;
    using Gui::isGui;
protected:
    bool isOnClick ();
    bool isOnMouse() const;
};