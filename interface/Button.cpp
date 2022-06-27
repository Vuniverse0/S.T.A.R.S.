#include "Button.h"

#define MAGIC_RATIO_BUTTONS 0.5f //TODO delete this shit, or no)))


Button::Button(void (*const&lambd)(), const std::string& a_string)
        :Gui(a_string, MAGIC_RATIO_BUTTONS, MAGIC_RATIO_BUTTONS)
        ,m_changer{lambd}
        ,m_normal_scale{Entry::m_sprite.getScale()}
        ,m_clickable{&m_sprite}
        ,m_suggestive{&m_sprite}
        ,m_activable{&m_sprite}
        ,m_onClick{m_normal_scale, &m_sprite}
{
    Entry::m_sprite.setOrigin( local_center( &(Entry::m_sprite) ) );//for nice size change
}


void Button::handle() {
    if ( m_suggestive.isMouseOn() && Entry::m_sprite.getScale().x - m_normal_scale.x < 0.03f ) {
        scale_by_mouse( &(Entry::m_sprite), true );
    }
    else if ( !m_suggestive.isMouseOn() && Sless(m_normal_scale, Entry::m_sprite.getScale())) {
        scale_by_mouse( &(Entry::m_sprite), false );
    }
    else if ( !m_suggestive.isMouseOn() && Entry::m_sprite.getScale() != m_normal_scale ) {
        Entry::m_sprite.setScale( m_normal_scale );
    }
    if ( m_clickable.isOnClick() ) {
        m_changer();
        m_onClick.click();
    }
}

void Button::handle(const sf::Event& event)
{
    assert(
        event.type == sf::Event::MouseMoved ||
        event.type == sf::Event::MouseButtonPressed ||
        event.type == sf::Event::MouseButtonReleased
    ); //use me only in this cases
    if ( m_activable.is_active() )
        m_clickable.handle(event);
    m_suggestive.handle(event);
}

void Button::enable(){ m_activable.enable(); }

void Button::disable(){ m_activable.disable(); }
