//
// Created by vuniverse on 10/22/21.
//

#pragma once

#include "typedefs_and_globals.h"
#include "Entry.h"

struct Handler {
private:
    sf::RenderWindow& window;
    sf::Time time_per_frame;
    bool paused = false;
public:
    static std::vector<Entry*> entry_list;
    static std::vector<Entry*> gui_list;
    mutable double_t x_ratio, y_ratio;
    Handler(sf::RenderWindow&, sf::VideoMode);

    void pause_switch();
    void handle();
    void update();
    void render();
    void set_fps(frames);
    void input(sf::Keyboard::Key key, bool isPressed);

};