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
    m_stepLeftCenterPanel = {static_cast<int>(m_stepLeftCenterPanel.x * Handler::x_ratio),
                             static_cast<int>(m_stepLeftCenterPanel.y * Handler::y_ratio) };
    m_anchor = anch;
    m_sprite.setTexture(*m_texture);
    m_sprite.setPosition(init(anch).x, init(anch).y);
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
    m_sprite.setScale(x, y);
    updateAnchor();
    m_located = {static_cast<int>(m_sprite.getGlobalBounds().left),
                 static_cast<int>(m_sprite.getGlobalBounds().top)};
}

sf::Vector2i Dashboard::m_stepLeftCenterPanel = {10, 15};
int Dashboard::locateLeftCenterPanel(Button& button)//locate button
{
    auto temp = m_located;
    m_located += {0,//static_cast<int>(rect.width)
                  static_cast<int>(button.sprite().getGlobalBounds().height) + m_stepLeftCenterPanel.y};
    button.sprite().setPosition(m_sprite.getGlobalBounds().width/2,
            static_cast<float>(button.sprite().getOrigin().y+temp.y)-15.f);
    return 0;
}

sf::Vector2i Dashboard::m_stepRightBottomPanel = {10, 15};
int Dashboard::locateRightBottomPanel(Button &button)
{

}
