//
// Created by vuniverse on 10/27/21.
//

#pragma once

#include "../utility/typedefs_and_globals.h"
#include "Animation.h"
#include "../core/Containers.h"


class Entry {
    friend Containers;
protected:
    sf::Vector2f m_normal_scale;
    sf::Sprite m_sprite;
    Animation m_animation;
    bool m_visibility{true};
    sf::Texture* m_texture = nullptr;
    sf::Texture m_object_texture;
    static std::vector<Entry*> m_all;
public:
    Entry() = delete;
    Entry(const std::string& a_string,
          frames a_frames, pixels size_x, pixels size_y);
    Entry(const std::string& a_string,
          frames a_frames, pixels a_pixels);
    Entry(const std::string& a_string);
    virtual ~Entry();
    void setAnimation(Animation& anim);
    bool isVisible()const;
    bool hide();
    bool show();
    virtual sf::Sprite& sprite();
    virtual void draw() = 0;//Draw to screen
    virtual void handle()=0;//Change properties
};


