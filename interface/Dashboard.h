//
// Created by vuniverse on 11/14/21.
//
#pragma once

#include "../utility/typedefs_and_globals.h"
#include "Gui.h"


enum class Anchor{
    LeftTop, RightTop, LeftBottom, RightBottom, CenterTop, CenterBottom, CenterRight, CenterLeft
};
class Dashboard : public Gui {
    friend Gui;
    struct Corner{
        static sf::Vector2f LeftTop(const sf::Sprite&);
        static sf::Vector2f RightTop(const sf::Sprite&);
        static sf::Vector2f LeftBottom(const sf::Sprite&);
        static sf::Vector2f RightBottom(const sf::Sprite&);
        static sf::Vector2f CenterTop(const sf::Sprite&);
        static sf::Vector2f CenterBottom(const sf::Sprite&);
        static sf::Vector2f CenterRight(const sf::Sprite&);
        static sf::Vector2f CenterLeft(const sf::Sprite&);
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
            case Anchor::CenterTop:
                return Corner::CenterTop(m_sprite);
            case Anchor::CenterBottom:
                return Corner::CenterBottom(m_sprite);
            case Anchor::CenterRight:
                return Corner::CenterRight(m_sprite);
            case Anchor::CenterLeft:
                return Corner::CenterLeft(m_sprite);
        }
    }
    sf::RenderTexture m_renderTexture;
    std::vector<sf::Sprite> m_attached;
    std::vector<Gui*> m_member;
public:
    Dashboard(Anchor anch, const std::string& a_string);
    bool add(Gui&);
    void handle() override ;
    void  draw(sf::RenderWindow& window) override ;
};