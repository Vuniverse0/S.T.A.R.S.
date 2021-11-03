//
// Created by vuniverse on 10/7/21.
//
#pragma once

#include "typedefs_and_globals.h"


struct Animation{
private:
    sf::Sprite& m_sprite_;

    std::vector<sf::Texture> m_frames_list_{};

    transformator m_transform_;
public:
    Animation();
    Animation(const std::string&, sf::Sprite&, pixels, frames);//Анимация из одной картинки(спрайтлист)
    Animation(const std::string&, sf::Sprite&, pixels, frames, transformator);//Анимация из одной картинки+кастом трансформатор
    Animation(const std::vector<std::string>&, sf::Sprite&);//Некоторое количевство картинок в анимацию
    Animation(transformator, sf::Sprite&);//Анимация посредством пользовательской функции(текстура едина)
    Animation(Animation const&);
    ~Animation();
    Animation& operator=(Animation&&) noexcept ;
    bool play(int8_t = 0, bool = false);//return true when m_animation finish
    int size() const;
    static sf::Texture generateTextureX(const std::string&, pixels, pixels = 0);
    static sf::Texture generateTextureXY(const std::string&, pixels, pixels , pixels = 0, pixels = 0);
private:
    static void default_tansformator_(sf::Sprite &sprite_t, const sf::Texture &texture_T);
    static void none_transformator_(sf::Sprite&, const sf::Texture&);
};