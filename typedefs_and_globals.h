//
// Created by vuniverse on 10/9/21.
//
#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "iostream"

#define GAME_MAKER_SCREEN_WIDTH 1366.0
#define GAME_MAKER_SCREEN_HEIGHT 768.0
#define DEFAULT_FPS 60

typedef uint8_t  frames;
typedef uint16_t pixels;
typedef uint16_t cords;
typedef void(*transformator)(sf::Sprite&, const sf::Texture &);

namespace Settings
{
    extern std::string resources;
    extern frames fps;
}

pixels operator "" _p(unsigned long long value);
frames operator "" _f(unsigned long long value);
