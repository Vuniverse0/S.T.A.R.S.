#include "typedefs_and_globals.h"
#include "../core/Handler.h"


pixels operator "" _p(unsigned long long value){return value;}

frames operator "" _f(unsigned long long value){return value;}

bool operator<(sf::Vector2f a_left, sf::Vector2f a_right)//x & y <
{
    return (a_left.x < a_right.x && a_left.y < a_right.y);
}

bool operator>(sf::Vector2f a_left, sf::Vector2f a_right)//x & y >
{
    return (a_left.x > a_right.x && a_left.y > a_right.y);
}

bool Sless(const sf::Vector2f& a_left, const sf::Vector2f& a_right)
{
    return (a_left.x < a_right.x && a_left.y < a_right.y);
}

namespace ratio {
    float_t valuable_ratio(){
        return
        Handler::gHandler->y_ratio > Handler::gHandler->x_ratio
        ?Handler::gHandler->x_ratio
        :Handler::gHandler->y_ratio;
    }
    float x_ratio(){
        return Handler::gHandler->x_ratio;
    }
    float y_ratio(){
        return Handler::gHandler->y_ratio;
    }
};