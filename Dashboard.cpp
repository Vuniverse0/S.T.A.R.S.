//
// Created by vuniverse on 11/14/21.
//

#include "Dashboard.h"
#include "Handler.h"


sf::Vector2f Dashboard::Corner::LeftTop(const sf::Sprite& sprite)
{
    return sf::Vector2f(0, 0);
}

sf::Vector2f Dashboard::Corner::RightTop(const sf::Sprite& sprite)
{
    return sf::Vector2f(Handler::window().getSize().x - sprite.getGlobalBounds().width + sprite.getOrigin().x,0);
}

sf::Vector2f Dashboard::Corner::LeftBottom(const sf::Sprite& sprite)
{
    return sf::Vector2f(0,Handler::window().getSize().y - sprite.getGlobalBounds().height + sprite.getOrigin().y);
}

sf::Vector2f Dashboard::Corner::RightBottom(const sf::Sprite& sprite)
{
    return sf::Vector2f(Handler::window().getSize().x - sprite.getGlobalBounds().width + sprite.getOrigin().x,
                        Handler::window().getSize().y - sprite.getGlobalBounds().height + sprite.getOrigin().y);
}


Dashboard::Dashboard(Anchor anch, const std::string& a_string, transformator a_transformator):
        Gui( 0, 0, a_string,  a_transformator)
{
    move(init(anch).x,init(anch).y);
}
