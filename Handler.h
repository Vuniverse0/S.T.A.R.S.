//
// Created by vuniverse on 10/22/21.
//

#pragma once

#include "typedefs_and_globals.h"


struct Handler {
private:
    sf::RenderWindow& window;
    double_t x,y;
public:
    explicit Handler(sf::RenderWindow& window, sf::VideoMode mode);
    void setFramesPerSecond();
    void input(sf::Keyboard::Key key, bool isPressed);

};