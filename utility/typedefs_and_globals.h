#pragma once

#include <SFML/Graphics.hpp>
#include <cstdint>
#include <utility>
#include <cmath>
#include <iostream>
#include <random>
#include <cassert>

#define GAME_MAKER_SCREEN_WIDTH 1366.0f //TODO remake these
#define GAME_MAKER_SCREEN_HEIGHT 768.0f //or not))) Any actor view like he want
#define DEFAULT_FPS 60 // keep))
#define EMPTY "null.png" //for Entry

typedef uint16_t  frames;
typedef uint16_t pixels;
typedef float_t cords;

//#include <nlohmann/json.hpp>
//using nlohmann::json;


namespace ratio {
    float_t valuable_ratio();
    float_t x_ratio();
    float_t y_ratio();
};

const auto binominal_float{
    [](float_t a_start, float_t a_end, float_t a_binominal)->float_t
    {
        if (a_end > 25 || a_start >= a_end || a_start < 0.f || a_binominal <= 0.f || a_binominal >= 1.f) {
            return -1.f;
        }
        unsigned long rand_lol;
        std::default_random_engine generator{rand_lol};
        int start = static_cast<uint8_t>(a_start*10), end = static_cast<uint8_t>(a_end*10);
        std::binomial_distribution<uint8_t> distribution((start + end), a_binominal);
        return (static_cast<float_t>(distribution(generator) - start)/10.f);
    }
};

const auto binominal_int{
    [](uint8_t a_start, uint8_t a_end, float_t a_binominal)->uint8_t
    {
        if (a_start >= a_end || a_binominal <= 0.f || a_binominal >= 1.f) {
            return 0;
        }
        unsigned long rand_lol;
        std::default_random_engine generator{rand_lol};
        std::binomial_distribution<uint8_t> distribution((a_start + a_end), a_binominal);
        return ((distribution(generator) - a_start));
    }
};

const auto size_regulator{
    [](const sf::Sprite*const sprite)->sf::FloatRect
    {
        auto l_bounds = (sprite->getGlobalBounds());
        l_bounds.width*0.6;//Todo check if this work(REALLY?)
        return l_bounds;
    }
};

const auto scale_by_mouse{//special tool TODO: move this
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

const auto center{//for code trigger - anchors(center of sprite on globals)
    [](const sf::Sprite*const sprite)->sf::Vector2f
    {
        auto temp = sprite->getGlobalBounds();
        return{temp.left + temp.width / 2.0f, temp.top + temp.height / 2.0f};
    }
};

const auto local_center{//for local center
    [](const sf::Sprite *const sprite)->sf::Vector2f
    {
        auto temp = sprite->getLocalBounds();
        return{temp.width / 2.0f, temp.height / 2.0f};
    }
};


const auto global_half{//for global center
        [](const sf::Sprite *const sprite)->sf::Vector2f
        {
            auto temp = sprite->getGlobalBounds();
            return{temp.width / 2.0f, temp.height / 2.0f};
        }
};


const auto window_center{
    [](sf::Vector2u size)->sf::Vector2f
    {
    return {static_cast<float_t>(size.x)/2.f, static_cast<float_t>(size.y)/2.f};
    }
};

pixels operator "" _p(unsigned long long);
frames operator "" _f(unsigned long long);
const auto no_callback{[](){}};

bool Sless(const sf::Vector2f&, const sf::Vector2f&);
//bool operator<(sf::Vector2f, sf::Vector2f);
//bool operator>(sf::Vector2f, sf::Vector2f);