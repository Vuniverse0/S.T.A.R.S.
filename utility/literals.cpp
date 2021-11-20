//
// Created by vuniverse on 10/24/21.
//
#include "typedefs_and_globals.h"

pixels operator "" _p(unsigned long long value)
{
    pixels  temp = value;
    return temp;
}

frames operator "" _f(unsigned long long value)
{
    frames  temp = value;
    return temp;
}

bool operator<(sf::Vector2f a_left, sf::Vector2f a_right)//x & y <
{
    return (a_left.x < a_right.x && a_left.y < a_right.y);
}

bool operator>(sf::Vector2f a_left, sf::Vector2f a_right)//x & y >
{
    return (a_left.x > a_right.x && a_left.y > a_right.y);
}

void no_callback()
{
}