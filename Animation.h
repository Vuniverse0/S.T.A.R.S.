//
// Created by vuniverse on 10/7/21.
//
#pragma once

#include "typedefs_and_globals.h"


struct Animation{
private:
    sf::Sprite& sprite;

    std::vector<sf::Texture> frames_list{};

    transformator transform;
public:
    Animation(const std::string&, sf::Sprite&, pixels, frames);//Анимация из одной картинки(спрайтлист)
    Animation(const std::string&, sf::Sprite&, pixels, frames, transformator);//Анимация из одной картинки+кастом трансформатор
    Animation(const std::vector<std::string>&, sf::Sprite&);//Некоторое количевство картонок в анимацию
    Animation(transformator, sf::Sprite&);//Анимация посредством пользовательской функции(текстура едина)
    Animation(Animation const&);
    ~Animation()=default;
    Animation& operator=(Animation&&);
    bool play(int8_t = 0, bool = false);//return true when animation finish
    static sf::Texture generateTextureX(const std::string&, pixels, pixels offset = 0);
    static sf::Texture generateTextureXY(const std::string&, pixels, pixels y, pixels offset_x = 0, pixels offset_y = 0);
private:
    static void standart_tansformator(sf::Sprite& sprite_t, const sf::Texture& texture_T);
};