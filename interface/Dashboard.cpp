//
// Created by vuniverse on 11/14/21.
//

#include "Dashboard.h"
#include "../core/Handler.h"
#include "../core/Containers.h"


Dashboard::Dashboard(Anchor anch, const std::string &a_string) : Gui(a_string)
{
    m_stepLeftCenterPanel = {static_cast<int>(m_stepLeftCenterPanel.x * Handler::x_ratio),
                             static_cast<int>(m_stepLeftCenterPanel.y * Handler::y_ratio) };
    m_anchor = anch;
    //m_sprite.setTexture(*m_texture);
    m_sprite.setPosition(Corner::ship(anch, m_sprite));
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
    m_sprite.setPosition(Corner::ship(m_anchor, m_sprite));
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
//TODO: int return value its "Costil" for testing init like initialization static unused variable in Handler
sf::Vector2i Dashboard::m_stepRightBottomPanel = {10, 15};
int Dashboard::locateRightBottomPanel(Button &button)
{

}
