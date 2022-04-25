#pragma once
#include "../utility/typedefs_and_globals.h"


enum class Anchor{
    LeftTop, RightTop,
    LeftBottom, RightBottom,
    CenterTop, CenterBottom,
    CenterRight, CenterLeft,
    Center
};

class Corner{
    static sf::Vector2f
            LeftTop(const sf::Sprite&),
            RightTop(const sf::Sprite&),
            LeftBottom(const sf::Sprite&),
            RightBottom(const sf::Sprite&),
            CenterTop(const sf::Sprite&),
            CenterBottom(const sf::Sprite&),
            CenterRight(const sf::Sprite&),
            CenterLeft(const sf::Sprite&),
            Center(const sf::Sprite&);
public:
    static sf::Vector2f ship(const Anchor&, const sf::Sprite&);
};