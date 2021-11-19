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

Dashboard::Dashboard(Anchor anch, const std::string &a_string):Gui(a_string)
{
    sf::Image image;

    image.loadFromFile(a_string);
    m_texture->loadFromImage(image);

    m_attached.emplace_back();
    m_attached[0].setTexture(*m_texture);

    m_renderTexture.create(image.getSize().x,image.getSize().y);

    m_sprite.setTexture(m_renderTexture.getTexture());
    m_sprite.setPosition(init(anch).x,init(anch).y);

    Containers::listGui.push_back(this);
}

bool Dashboard::add(Gui& tracked)
{
    m_attached.emplace_back();
    m_attached[m_attached.size()-1].setTexture(*tracked.getAttach());
    m_member.push_back(&tracked);
    return false;
}

void Dashboard::handle()
{
    for (auto& item : m_member)
        item->handle();
}

void Dashboard::draw(sf::RenderWindow &window)
{
    m_renderTexture.clear(sf::Color(sf::Color::Transparent));
    for (auto& item : m_attached) {
        m_renderTexture.draw(item);
    }
    //m_sprite.setTexture(m_renderTexture.getTexture());
    window.draw(m_sprite);
}
