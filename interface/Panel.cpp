#include "Panel.h"
#include "../core/Handler.h"

void Panel::draw(sf::RenderTarget& target, const sf::RenderStates& states) const
{
    if ( !m_visibility )
        return;
    target.draw(m_sprite, states);
    for (auto it : m_buttons)
        it->draw(target, states);
}

void Panel::handle()
{
    for(auto it : m_buttons)
        it->handle();
}

void Panel::handle(const sf::Event& event)
{
    for(auto it : m_buttons)
        it->handle(event);
}

Panel::Panel(const IGroup<Button>& a_group, const Sprite& a_sprite) : Sprite(a_sprite), m_buttons{a_group}
{
    m_sprite.setPosition(Corner::ship(Anchor::CenterLeft, m_sprite));
    Place::group<Vertical>(
            {m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width / 2.f,
             m_sprite.getGlobalBounds().top + m_sprite.getGlobalBounds().height/2.f},
            15.f * ratio::valuable_ratio(), m_buttons);
}
