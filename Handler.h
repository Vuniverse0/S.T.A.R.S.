//
// Created by vuniverse on 10/22/21.
//

#pragma once

#include "typedefs_and_globals.h"
#include "Entry.h"

struct Handler {//singleton
private:
    static bool m_singleton;
    sf::RenderWindow& m_window;
    sf::Time m_time_per_frame;
    bool m_IsPaused = false;
public:
    static float_t x_ratio, y_ratio;

    Handler(sf::RenderWindow& window, sf::VideoMode modee);
    ~Handler();

    sf::RenderWindow& window();
    void pause_switch();
    void handle();
    void update();
    void render();
    void set_fps(const frames&);
    void input(const sf::Keyboard::Key& key, const bool& isPressed);

};