#include "Gui.h"


bool Clickable::isOnClick()
{
    if ( m_mouse ) m_mouse = false;
    else return false;
    return true;
}

void Clickable::m_handle(const sf::Event& event)
{
    if (sf::Event::MouseButtonReleased == event.type)
        m_mouse = size_regulator(m_p_sprite).contains(event.mouseButton.x, event.mouseButton.y);
}


void Suggestive::m_handle(const sf::Event& event) {
    if ( sf::Event::MouseMoved == event.type )
        m_mouse = size_regulator(m_p_sprite).contains(event.mouseMove.x, event.mouseMove.y);
}

bool Suggestive::isMouseOn() const { return m_mouse; }

void Shorten::click(){ m_mouse = true; }

void Shorten::m_handle()
{
    if ( m_mouse ) {
        if ( m_p_sprite->getScale().x > m_normal_scale.x) {
            scale_by_mouse( m_p_sprite, false );
            scale_by_mouse( m_p_sprite, false );
        } else {
            m_mouse = false;
        }
    }
}

Clickable::Clickable() { Insert(m_list); }
Suggestive::Suggestive() { Insert(m_list); }
Shorten::Shorten() { Insert(m_list); }