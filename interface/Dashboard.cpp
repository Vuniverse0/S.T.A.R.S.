//
// Created by vuniverse on 11/14/21.
//

#include "Dashboard.h"
#include "../core/Handler.h"


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

Dashboard::Dashboard(Anchor anch, const std::string &a_string):Gui(a_string)
{
    sf::Image image;
    sf::Texture texture;

    image.loadFromFile(a_string);
    texture.loadFromImage(image);

    m_attached.emplace_back();
    m_attached[0].setTexture(texture);

    m_renderTexture.create(image.getSize().x,image.getSize().y);

    m_sprite.setTexture(m_renderTexture.getTexture());
    m_sprite.setPosition(init(anch).x,init(anch).y);
}

bool Dashboard::add(Gui& tracked)
{
    m_attached.emplace_back();
    m_attached[m_attached.size()-1].setTexture(*tracked.getAttach());
    return false;
}

void Dashboard::handle() {

}

void Dashboard::draw(sf::RenderWindow &window) {

}
