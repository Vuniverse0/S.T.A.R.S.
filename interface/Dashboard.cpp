//
// Created by vuniverse on 11/14/21.
//

#include "Dashboard.h"
#include "../core/Handler.h"
#include "../core/Containers.h"

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

sf::Vector2f Dashboard::Corner::CenterTop(const sf::Sprite& sprite)
{
    return sf::Vector2f(Handler::window().getSize().x/2-global_center(&sprite).x,0);
}

sf::Vector2f Dashboard::Corner::CenterBottom(const sf::Sprite& sprite)
{
    return sf::Vector2f(
            Handler::window().getSize().x/2-global_center(&sprite).x,
            Handler::window().getSize().y - sprite.getGlobalBounds().height + sprite.getOrigin().y);
}

sf::Vector2f Dashboard::Corner::CenterRight(const sf::Sprite& sprite)
{
    return sf::Vector2f(
            Handler::window().getSize().x - sprite.getGlobalBounds().width + sprite.getOrigin().x,
            Handler::window().getSize().y/2-global_center(&sprite).y);
}

sf::Vector2f Dashboard::Corner::CenterLeft(const sf::Sprite& sprite)
{
    return sf::Vector2f(0,Handler::window().getSize().y/2-global_center(&sprite).y);
}

sf::Vector2f Dashboard::Corner::Center(const sf::Sprite& sprite)
{
    return sf::Vector2f(Handler::window().getSize().x/2-global_center(&sprite).x,
                        Handler::window().getSize().y/2-global_center(&sprite).y);
}

Dashboard::Dashboard(Anchor anch, const std::string &a_string) : Gui(a_string)
{
    m_step = {static_cast<int>(m_step.x * Handler::x_ratio), 
              static_cast<int>(m_step.y * Handler::y_ratio) };
    m_anchor = anch;
    m_sprite.setTexture(*m_texture);
    m_sprite.setPosition(init(anch).x,init(anch).y);
    Containers::listGui.push_back(this);
    m_located = {static_cast<int>(m_sprite.getGlobalBounds().left),
                 static_cast<int>(m_sprite.getGlobalBounds().top)};
}

void Dashboard::handle()
{
}

void Dashboard::draw(sf::RenderWindow &window)
{
    window.draw(m_sprite);
}

void Dashboard::updateAnchor()
{
    m_sprite.setPosition(init(m_anchor).x,init(m_anchor).y);
}

void Dashboard::scale(float_t x, float_t y) {
    Entry::scale(x, y);
    updateAnchor();
}

sf::Vector2i Dashboard::m_step = {30,30};
sf::Vector2i Dashboard::locate(const sf::FloatRect & rect) {
    auto temp = m_located;
    m_located += {0,//static_cast<int>(rect.width)
                  static_cast<int>(rect.height)};
    std::cout<<m_located.x <<" "<<m_located.y<<std::endl;
    return { (temp.x+m_step.x),  (temp.y+m_step.y)};
}