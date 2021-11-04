//
// Created by vuniverse on 10/9/21.
//
#pragma once

#include <SFML/Graphics.hpp>

#include <cstdint>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iostream>

#define GAME_MAKER_SCREEN_WIDTH 1366.0
#define GAME_MAKER_SCREEN_HEIGHT 768.0
#define DEFAULT_FPS 60

typedef uint8_t  frames;
typedef uint16_t pixels;
typedef float_t cords;
typedef void ( *transformator )( sf::Sprite&, const sf::Texture& );

namespace Settings
{
    extern std::string g_resources;
    extern frames g_fps;
    extern sf::RenderWindow* g_window;
}

pixels operator "" _p(unsigned long long value);
frames operator "" _f(unsigned long long value);
