#pragma once

#include "../primitives/Entry.h"
#include "Place.h"
#include "../primitives/Group.h"

using Event = const sf::Event&;//TODO REMOVE


struct Gui : Entry{
    using Entry::Entry;
    ~Gui() override = default;
};

struct Clickable{
    void handle(const sf::Event& event);
    [[nodiscard]] bool isOnClick();
    explicit Clickable(sf::Sprite* a_p_sprite);
protected:
    sf::Sprite* m_p_sprite;
private:
    bool m_mouse{false};
};

struct Suggestive{
    void handle(const sf::Event& event);
    [[nodiscard]] bool isMouseOn() const;
    explicit Suggestive(sf::Sprite* a_p_sprite);
protected:
    sf::Sprite* m_p_sprite;
private:
    bool m_mouse{false};
};

struct Shorten{
    void handle();
    void click();
    explicit Shorten(sf::Vector2f a_normal_scale, sf::Sprite* a_p_sprite);
protected:
    sf::Sprite* m_p_sprite;
private:
    sf::Vector2f m_normal_scale;
    bool m_mouse{false};
};

struct Activable{
    void enable();
    void disable();
    [[nodiscard]] bool is_active() const;
    explicit Activable(sf::Sprite* a_p_sprite);
protected:
    sf::Sprite* m_p_sprite;
private:
    bool m_active{true};
};

struct Unfold{
    Unfold(Direction direction, sf::Sprite* a_p_sprite, Group_I& a_group, float_t separator);
    bool unfold();
    bool fold();
private:
    bool handle( bool fold );
    Direction m_direction{None};
    sf::Sprite* m_p_sprite;
    Group_I& m_group;
    float_t sum_a, m_separator;
};