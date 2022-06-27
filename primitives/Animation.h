//
// Created by vuniverse on 10/7/21.
#pragma once

#include "../utility/typedefs_and_globals.h"


struct Animation{
private:
    sf::Sprite* m_sprite;
    sf::Texture m_texture{};
    const sf::Texture* m_alt_texture{nullptr};
    frames m_i{0}, m_count;
    pixels m_size_x, m_size_y;
    float_t counter = 1.0f;
public:
    //Animation();
    Animation(const std::string& a_sheet, sf::Sprite& a_sprite_p, pixels a_size_x, pixels a_size_y, frames a_count = 0);
    Animation(Animation const& other) = default;
    Animation& operator=(Animation&& other) = delete;
    Animation& operator=(const Animation& other);
    ~Animation() = default;
    bool play(float_t speed = 1, bool direction = false);//return true when m_animation finish
    bool stop( bool setAlt );
};