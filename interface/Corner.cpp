//
// Created by vuniverse on 11/26/21.
//

#include "Corner.h"
#include "../core/Handler.h"


sf::Vector2f Corner::ship(const Anchor& anch, const sf::Sprite& m_sprite)
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
        case Anchor::Center:
            return Corner::Center(m_sprite);
    }
}

sf::Vector2f Corner::LeftTop(const sf::Sprite& sprite)
{
    return sf::Vector2f(0, 0);
}

sf::Vector2f Corner::RightTop(const sf::Sprite& sprite)
{
    return sf::Vector2f(Handler::window().getSize().x - sprite.getGlobalBounds().width + sprite.getOrigin().x,0);
}

sf::Vector2f Corner::LeftBottom(const sf::Sprite& sprite)
{
    return sf::Vector2f(0,Handler::window().getSize().y - sprite.getGlobalBounds().height + sprite.getOrigin().y);
}

sf::Vector2f Corner::RightBottom(const sf::Sprite& sprite)
{
    return sf::Vector2f(Handler::window().getSize().x - sprite.getGlobalBounds().width + sprite.getOrigin().x,
                        Handler::window().getSize().y - sprite.getGlobalBounds().height + sprite.getOrigin().y);
}

sf::Vector2f Corner::CenterTop(const sf::Sprite& sprite)
{
    return sf::Vector2f(Handler::window().getSize().x/2-global_center(&sprite).x,0);
}

sf::Vector2f Corner::CenterBottom(const sf::Sprite& sprite)
{
    return sf::Vector2f(
            Handler::window().getSize().x/2-global_center(&sprite).x,
            Handler::window().getSize().y - sprite.getGlobalBounds().height + sprite.getOrigin().y);
}

sf::Vector2f Corner::CenterRight(const sf::Sprite& sprite)
{
    return sf::Vector2f(
            Handler::window().getSize().x - sprite.getGlobalBounds().width + sprite.getOrigin().x,
            Handler::window().getSize().y/2-global_center(&sprite).y);
}

sf::Vector2f Corner::CenterLeft(const sf::Sprite& sprite)
{
    return sf::Vector2f(0,Handler::window().getSize().y/2-global_center(&sprite).y);
}

sf::Vector2f Corner::Center(const sf::Sprite& sprite)
{
    return sf::Vector2f(Handler::window().getSize().x/2-global_center(&sprite).x,
                        Handler::window().getSize().y/2-global_center(&sprite).y);
}