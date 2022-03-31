#pragma once

#include "Gui.h"


class Button : public Gui, Clickable, Suggestive, Shorten {
    friend Traceable<>;
    Traceable<>::List_Funct<Button> m_list;
    Changer_I* m_changer;
    sf::Vector2f m_normal_scale{};
    void m_handle();
public:
    Button(Changer_I& lambd, const std::string& a_string);
    ~Button() override = default;
    using Traceable<const sf::Event&>::handle;
    void handle() override;
};