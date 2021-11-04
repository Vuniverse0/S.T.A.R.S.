//
// Created by vuniverse on 10/7/21.
//
#pragma once

#include "typedefs_and_globals.h"


struct Animation{
private:
    sf::Sprite& m_sprite;
    std::vector<sf::Texture> m_frames_list{};
    transformator m_transform;
public:
    Animation();
    Animation(const std::string&, sf::Sprite&, pixels, frames);//Анимация из одной картинки(спрайтлист)
    Animation(const std::string&, sf::Sprite&, pixels, frames, transformator);//Анимация из одной картинки+кастом трансформатор
    Animation(const std::vector<std::string>&, sf::Sprite&);//Некоторое количевство картинок в анимацию
    Animation(transformator, sf::Sprite&);//Анимация посредством пользовательской функции(текстура едина)
    Animation(Animation const&);
    ~Animation() = default;
    Animation& operator=(Animation&&) noexcept ;

    bool play(int8_t = 0, bool = false);//return true when m_animation finish
    int size() const;

    static sf::Texture generateTextureX(const std::string&, const pixels&, const pixels& = 0);
    static sf::Texture generateTextureXY(const std::string&, const pixels&, const pixels&,
                                                             const pixels& = 0, const pixels& = 0);
    static void default_transformator(sf::Sprite &sprite_t, const sf::Texture &texture_T);
    static void none_transformator(sf::Sprite&, const sf::Texture&);
};