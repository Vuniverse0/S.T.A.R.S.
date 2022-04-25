#include "Button.h"
#define MAGIC_RATIO_BUTTONS 0.5f //TODO delete this shit, or no)))


Button::Button(Changer_I& lambd, const std::string &a_string) :
        Gui(a_string, MAGIC_RATIO_BUTTONS, MAGIC_RATIO_BUTTONS),
        Shorten(),
        m_changer{&lambd},
        m_list{this, &Button::m_handle}
{
    Traceable<>::m_p_sprite = Traceable<const sf::Event&>::m_p_sprite = &m_sprite;
    Shorten::m_normal_scale = Button::m_normal_scale = Entry::m_sprite.getScale();
    Traceable<>::Insert(m_list);
    Entry::m_sprite.setOrigin( local_center( &(Entry::m_sprite) ) );
}

void Button::m_handle() {
    if ( isMouseOn() && Entry::m_sprite.getScale().x - m_normal_scale.x < 0.03f ) {
        scale_by_mouse( &(Entry::m_sprite), true );
    }
    else if ( !isMouseOn() && Entry::m_sprite.getScale() > m_normal_scale) {
        scale_by_mouse( &(Entry::m_sprite), false );
    }
    else if ( !isMouseOn() && Entry::m_sprite.getScale() != m_normal_scale ) {
        Entry::m_sprite.setScale( m_normal_scale );
    }
    if ( isOnClick() ) {
        m_changer->call();
        click();
    }
}

void Button::handle() { Traceable<>::handle(); }

void Button::handle( Event event ) { Traceable<const sf::Event&>::handle( event ); }
