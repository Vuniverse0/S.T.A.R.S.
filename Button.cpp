//
// Created by vuniverse on 11/2/21.
//

#include "Button.h"

#include <utility>
#include "Containers.h"


Button::Button(cords a_x, cords a_y, sf::Sprite sprite) : Gui(a_x, a_y)
{
    m_sprite_ = std::move(sprite);
    Containers::button_list.push_back(this);
}

Button::~Button()
{
    Containers::erase(Containers::button_list, this);
}

void Button::checkClick(sf::Vector2f a_mousePos) {
    if (m_sprite.getGlobalBounds().contains(a_mousePos.x,a_mousePos.y))
        m_current_ = true;
//    sf::Vector2f spriteSize(
//            m_sprite.getTexture()->getSize().x * m_sprite.getScale().x,
//            m_sprite.getTexture()->getSize().y * m_sprite.getScale().y);
//    if (a_mousePos.x > m_sprite.getPosition().x && a_mousePos.x < (m_sprite.getPosition().x + spriteSize.x)) {
//        if(a_mousePos.y > m_sprite.getPosition().y && a_mousePos.y < (m_sprite.getPosition().y + spriteSize.y)) {
//            m_current_=true;
//        }
//    }
}

bool Button::isOnClick()
{
    if(m_current_){
        m_current_ = false;
        return true;
    }
    return false;
}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite_);
}

