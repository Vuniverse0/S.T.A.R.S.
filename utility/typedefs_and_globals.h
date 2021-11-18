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

#define GAME_MAKER_SCREEN_WIDTH 1366.0f //TODO remake these
#define GAME_MAKER_SCREEN_HEIGHT 768.0f
#define DEFAULT_FPS 60 // keep
#define F_PI 3.14159265358979323846f
#define EMPTY "null.png"

typedef uint8_t  frames;
typedef uint16_t pixels;
typedef float_t cords;

static auto size_regulator{
        [](const sf::Sprite*const sprite)->sf::FloatRect
        {
            auto l_bounds = (sprite->getGlobalBounds());
            l_bounds.width*0.6;
            return l_bounds;
        }
};

static auto scale_by_mouse{
        [](sf::Sprite*const sprite, bool focus)->void
        {
            if (focus) {
                sprite->scale(1.01f, 1.01f);
            }
            else {
                sprite->scale(0.99f, 0.99f);
            }
        }
};

static auto center{//for code trigger - anchors
        [](const sf::Sprite*const sprite)->sf::Vector2f
        {
            auto temp = sprite->getGlobalBounds();
            return{temp.left + temp.width / 2.0f, temp.top + temp.height / 2.0f};
        }
};

static auto local_center{//for .setOrigin by local center
        [](const sf::Sprite*const sprite)->sf::Vector2f
        {
            auto temp = sprite->getLocalBounds();
            return{temp.width / 2.0f, temp.height / 2.0f};
        }
};

pixels operator "" _p(unsigned long long);
frames operator "" _f(unsigned long long);

bool operator<(sf::Vector2f, sf::Vector2f);
bool operator>(sf::Vector2f, sf::Vector2f);