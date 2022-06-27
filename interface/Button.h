#pragma once

#include "Gui.h"


class Button : public Gui{
    sf::Vector2f m_normal_scale{};
    Shorten m_onClick;
    Clickable m_clickable;
    Suggestive m_suggestive;
    Activable m_activable;
    decltype(+[]{}) m_changer;
public:
    explicit Button(void (*const&lambd)(), const std::string& a_string);
    ~Button() override = default;
    void handle() override;
    void handle(const sf::Event& event) override; //MouseMoved || MouseButtonReleased || MouseButtonPresed
    void enable();
    void disable();
};