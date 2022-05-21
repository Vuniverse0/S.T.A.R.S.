#pragma once

#include "../primitives/Group.h"
#include "Corner.h"
#include "../primitives/Sprite.h"
#include "Button.h"


class Panel : public Sprite {
    IGroup<Button> m_buttons;
public:
    Panel(const IGroup<Button>& a_group, const Sprite& a_sprite);
    void draw(sf::RenderWindow& window = defaultRenderWindow()) override;
    void handle() override;
    void handle( const sf::Event& ) override;
};