//
// Created by vuniverse on 11/22/21.
//

#pragma once

#include "../utility/typedefs_and_globals.h"


enum class Body{Asteroid, Moon, Planet, Star, Hole, System, Galaxy};
enum class Planet{Wet, Dry, Islands, Stone,  Gas, Rings, Ice, Lava};
enum class Star{White, Red, Blue, Purple, Other, Black};

union Set{
    struct{
        uint8_t m0 : 1;
        uint8_t m1 : 1;
        uint8_t m2 : 1;
        uint8_t m3 : 1;
        uint8_t m4 : 1;
        uint8_t m5 : 1;
        uint8_t m6 : 1;
        uint8_t m7 : 1;
    };
private:
    uint8_t set = 0;
};

union Type{
    Planet planet;
    Star star;
};

struct MetaDataBody{
    float_t speed;
    float_t size;
    float_t spin;
};

struct MetaDataObject{
    Body body;
    Type type;
    std::string file;
};