//
// Created by vuniverse on 10/9/21.
//
#pragma once

#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include <cstdint>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <random>

#define GAME_MAKER_SCREEN_WIDTH 1366.0f //TODO remake these
#define GAME_MAKER_SCREEN_HEIGHT 768.0f //or not))) Any actor view like he want
#define VALUABLE_RATIO ((Handler::y_ratio > Handler::x_ratio) ?  Handler::x_ratio : Handler::y_ratio)
#define DEFAULT_FPS 60 // keep
#define F_PI 3.14159265358979323846f
#define EMPTY "null.png"

typedef uint16_t  frames;
typedef uint16_t pixels;
typedef float_t cords;

using nlohmann::json;

static auto binominal_float{
        [](float_t a_start, float_t a_end, float_t a_binominal)->float_t
        {
            if (a_end > 25 || a_start >= a_end || a_start < 0.f || a_binominal <= 0.f || a_binominal >= 1.f) {
                return -1.f;
            }
            std::default_random_engine generator;
            int start = static_cast<uint8_t>(a_start*10), end = static_cast<uint8_t>(a_end*10);
            std::binomial_distribution<uint8_t> distribution((start + end), a_binominal);
            return ((distribution(generator) - start)/10.f);
        }
};

static auto binominal_int{
        [](uint8_t a_start, uint8_t a_end, float_t a_binominal)->uint8_t
        {
            if (a_start >= a_end || a_binominal <= 0.f || a_binominal >= 1.f) {
                return 0;
            }
            std::default_random_engine generator;
            std::binomial_distribution<uint8_t> distribution((a_start + a_end), a_binominal);
            return ((distribution(generator) - a_start));
        }
};

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

static auto local_center{//for local center
        [](const sf::Sprite*const sprite)->sf::Vector2f
        {
            auto temp = sprite->getLocalBounds();
            return{temp.width / 2.0f, temp.height / 2.0f};
        }
};

static auto global_center{//for global center without top&left
        [](const sf::Sprite*const sprite)->sf::Vector2f
        {
            auto temp = sprite->getGlobalBounds();
            return{temp.width / 2.0f, temp.height / 2.0f};
        }
};

pixels operator "" _p(unsigned long long);
frames operator "" _f(unsigned long long);
void no_callback();
bool operator<(sf::Vector2f, sf::Vector2f);
bool operator>(sf::Vector2f, sf::Vector2f);