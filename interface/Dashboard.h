//
// Created by vuniverse on 11/14/21.
//
#pragma once

#include "../utility/typedefs_and_globals.h"
#include "Gui.h"
#include "Button.h"
#include "Corner.h"


class Dashboard : public Gui {
    friend Gui;
    void updateAnchor();
    Anchor m_anchor;
    sf::Vector2i m_located;
    static sf::Vector2i m_stepLeftCenterPanel;
    static sf::Vector2i m_stepRightBottomPanel;
public:
    static std::vector<Dashboard*> m_all;
public:
    Dashboard(Anchor anch, const std::string& a_string);
    ~Dashboard() override;
    void locateLeftCenterPanel(Button& button);
    int locateRightBottomPanel(Button& button);

    void scale(float_t x, float_t y);
    void draw() override ;
    void handle() override ;
};