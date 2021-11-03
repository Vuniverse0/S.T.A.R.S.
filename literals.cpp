//
// Created by vuniverse on 10/24/21.
//
#include "typedefs_and_globals.h"

frames Settings::g_fps{DEFAULT_FPS};

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