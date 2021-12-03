//
// Created by vuniverse on 11/2/21.
//

#include "../core/Containers.h"
#include "../core/Handler.h"
#include "Button.h"

#define MAGIC_RATIO_BUTTONS 0.5f //TODO delete this shit, or no)))

std::vector<Button*> Button::m_all;

Button::Button(const std::string& a_string, void(*callback)()) :
                Gui(a_string), m_flags{}
{
    m_callback = callback;
    m_sprite.scale(MAGIC_RATIO_BUTTONS * Handler::x_ratio,MAGIC_RATIO_BUTTONS * Handler::y_ratio);
    m_normal_scale = m_sprite.getScale();
    m_sprite.setOrigin(local_center(&m_sprite));
    Containers::drawTrait(this);
    m_all.push_back(this);
}

Button::~Button()
{
    Containers::erase(this);
}

void Button::checkClick(sf::Vector2i a_mousePos)
{
    if (size_regulator(&m_sprite).contains(a_mousePos.x,a_mousePos.y))
        m_flags.m_current = 1;
}

void Button::checkMouse(sf::Vector2i a_mousePos)
{
    if (size_regulator(&m_sprite).contains(a_mousePos.x,a_mousePos.y)) {
        m_flags.m_mouse = 1;
    }
    else {
        m_flags.m_mouse = 0;
    }
}

bool Button::isOnClick()//if true, turn off click flag
{
    if (m_flags.m_current == 1) {
        m_flags.m_current = 0;
        return true;
    }
    return false;
}

bool Button::isOnMouse() const
{
    return m_flags.m_mouse == 1;
}

void Button::draw(sf::RenderWindow& window)
{
    if (isOnMouse()) {
        if (m_sprite.getScale().x - m_normal_scale.x < 0.05f) {
            scale_by_mouse(&m_sprite, true);
        }
    }
    else if (m_sprite.getScale() > m_normal_scale) {
        scale_by_mouse(&m_sprite, false);
    }
    else if (m_sprite.getScale() != m_normal_scale) {
        m_sprite.setScale(m_normal_scale);
    }
    window.draw(m_sprite);
}

void Button::handle()
{
    if (isOnClick()) {
        m_callback();
    }
}

void Button::handle(sf::Event event)
{
    if (event.type == sf::Event::MouseMoved) {
        for (auto &item : m_all)
            item->checkMouse({event.mouseMove.x, event.mouseMove.y});
    }
    else if (event.type == sf::Event::MouseButtonReleased) {
        for (auto &item : m_all)
            item->checkClick({event.mouseButton.x, event.mouseButton.y});
    }
}