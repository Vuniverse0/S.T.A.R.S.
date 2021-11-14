//
// Created by vuniverse on 10/22/21.
//

#pragma once

#include "typedefs_and_globals.h"
#include "Entry.h"

struct Handler {//singleton
private:
    Handler() noexcept ;
    static sf::RenderWindow m_window;
    sf::Time m_time_per_frame;
    bool m_IsPaused = false;
public:
    static sf::Clock clock;
    static Handler gHandler;
    static float_t x_ratio, y_ratio;
    ~Handler();
    static sf::RenderWindow& window();
    void pause_switch();
    static void handle();
    void update();
    static void render();
    void event();
    void set_fps(const frames&);
    void input(const sf::Keyboard::Key& key, const bool& isPressed);
};