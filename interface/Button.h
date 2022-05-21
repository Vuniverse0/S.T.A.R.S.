#pragma once

#include "Gui.h"

#define MAGIC_RATIO_BUTTONS 0.5f //TODO delete this shit, or no)))


class Button : public Gui, Clickable, Suggestive, Shorten {
    using lamblaT = decltype(+[]{});
    friend Traceable<>;
    Traceable<>::List_Funct<Button> m_list;
    lamblaT m_changer;
    sf::Vector2f m_normal_scale{};
    void m_handle();
public:
    explicit Button(void (*const&lambd)(), const std::string& a_string);
    ~Button() override = default;
    void handle() override;
    void handle( Event ) override;
};