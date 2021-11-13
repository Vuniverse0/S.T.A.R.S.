//
// Created by vuniverse on 10/7/21.
#pragma once

#include "typedefs_and_globals.h"


struct Animation{
private:
    sf::Sprite& m_sprite;
    std::vector<sf::Texture> m_frames_list{};
    transformator m_transform;
    frames m_i;
    float_t counter = 1.0f;
public:
    //Animation();
    Animation() = delete;
    Animation(const std::string& a_sheet, sf::Sprite& a_sprite_p, pixels a_size, frames a_count );
    //Анимация из одной картинки(спрайтлист) одна полоса
    Animation(const std::string& a_sheet, sf::Sprite& a_sprite_p,
              pixels a_size, frames a_count, transformator custom_transformator);
    //Анимация из одной картинки+кастом трансформатор
    Animation(const std::vector<std::string>& init_list, sf::Sprite& sprite_p);
    //Некоторое количевство картинок в анимацию
    Animation(const std::string& a_sheet, sf::Sprite& a_sprite_p, pixels a_size_x,
            pixels a_size_y,frames a_frames_per_line, frames a_count);
    //Анимация из одной картинки(спрайтлист) много полос
    Animation(transformator transform_funk, sf::Sprite& sprite_p);
    //Анимация посредством пользовательской функции(текстура едина)
    Animation(Animation const& other);
    Animation& operator=(Animation&& other) noexcept ;
    ~Animation() = default;

    bool play(float_t speed = 1, bool direction = false);//return true when m_animation finish
    int size() const;

    static sf::Texture generateTextureX(const std::string& texture, const pixels& size, const pixels& offset = 0);
    static sf::Texture generateTextureXY(const std::string& texture, const pixels& x, const pixels& y,
                                         const pixels& offset_x = 0, const pixels& offset_y = 0);
public:
    static void default_transformator(sf::Sprite &sprite_t, const sf::Texture &texture_T);
    static void none_transformator(sf::Sprite&, const sf::Texture&);
};