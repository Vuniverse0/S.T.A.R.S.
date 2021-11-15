//
// Created by vuniverse on 11/14/21.
//
#pragma once

#include "typedefs_and_globals.h"
#include "Gui.h"


enum class Anchor{
    LeftTop, RightTop, LeftBottom, RightBottom
};
class Dashboard : public Gui {
    struct Corner{
        static sf::Vector2f LeftTop(const sf::Sprite&);
        static sf::Vector2f RightTop(const sf::Sprite&);
        static sf::Vector2f LeftBottom(const sf::Sprite&);
        static sf::Vector2f RightBottom(const sf::Sprite&);
    };
    sf::Vector2f init(const Anchor& anch)
    {
        switch (anch) {
            case Anchor::LeftTop:
                return Corner::LeftTop(m_sprite);
            case Anchor::RightTop:
                return Corner::RightTop(m_sprite);
            case Anchor::LeftBottom:
                return Corner::LeftBottom(m_sprite);
            case Anchor::RightBottom:
                return Corner::RightBottom(m_sprite);
        }
    }
public:
    Dashboard(Anchor anch, const std::string& a_string, transformator a_transformator);

    using Gui::isAnimated;
};