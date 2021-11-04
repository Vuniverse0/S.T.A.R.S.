//
// Created by vuniverse on 11/2/21.
//

#include "Containers.h"
#include "Handler.h"


Button::Button(cords a_x, cords a_y, const std::string& a_string, transformator a_transformator) :
                Gui(a_x, a_y, a_string, a_transformator)
{
    Containers::listButton.push_back(this);
    m_sprite.scale(0.5f * Handler::x_ratio,0.5f * Handler::y_ratio);
}

Button::~Button()
{
    Containers::erase(Containers::listButton, this);
}

void Button::checkClick(sf::Vector2i a_mousePos) {
    auto size_regulator{[this](){auto l_bounds = (this->m_sprite.getGlobalBounds());
                                                    l_bounds.height;
                                                    l_bounds.width*0.6;
                                                    return l_bounds;}};

    if (size_regulator().contains(a_mousePos.x,a_mousePos.y))
        m_current = true;
}

bool Button::isOnClick()
{
    if(m_current){
        m_current = false;
        return true;
    }
    return false;
}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}

bool Button::isOnMouse(sf::Vector2i a_mousePos)
{
    auto size_regulator{[this](){auto l_bounds = (this->m_sprite.getGlobalBounds());
        l_bounds.height;
        l_bounds.width*0.6;
        return l_bounds;}};

    if (size_regulator().contains(a_mousePos.x,a_mousePos.y)){
        if(m_sprite.getScale().x<1.2){
            m_sprite.scale(1.05,1.05);
        }
        return true;
    }else{
        if(m_sprite.getScale().x>=1){
            m_sprite.scale(0.95,0.95);
        }
        return false;
    }
}