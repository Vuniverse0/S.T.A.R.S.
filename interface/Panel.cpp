#include "Panel.h"


Panel::Panel(const IGroup<Button>& a_group, const Sprite& a_sprite) : Sprite(a_sprite), m_buttons{a_group}{}

void Panel::draw(sf::RenderWindow& window) {
    Entry::draw(window);
    for(auto& it : m_buttons){
        it->draw(window);
    }
}

void Panel::handle() {
    for(auto& it : m_buttons){
        it->handle();
    }
}

void Panel::handle(const sf::Event& event) {
    for(auto& it : m_buttons){
        it->handle(event);
    }
}