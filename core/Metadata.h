//
// Created by vuniverse on 11/22/21.
//

#pragma once

#include "../utility/typedefs_and_globals.h"


enum class Body{Asteroid, Moon, Planet, Star, Hole, System};
enum class Planets{ Wet, Dry, Islands, Stone,  Gas, Rings, Ice, Lava};
enum class Moons{ Stone, Gas, Ice, Dry};
enum class Stars{ White, Red, Blue, Purple, Other, Black};
//enum class Systems Number of objects
enum class Asteroid{ Classic, Ore, Material};
enum class Holes{ Classic, Material, Gate, Math};
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
    uint8_t set = 0;
};

union Type{
    unsigned int member;
    Planets planet;
    Stars star;
    Moons moon;
    Asteroid asteroid;
    Holes hole;
};

struct Sets{
    Set first;
    Set second;
};

struct MetaDataBody{
    float_t speed;
    float_t bsize;
    float_t spin;
};

struct MetaDataObject{
    Body body;
    Type type;
    Sets sets;
    std::string file;
};

void from_json(const json& j, MetaDataBody& p);
void from_json(const json& j, MetaDataObject& p);
void to_json(json& j, const MetaDataBody& p);
void to_json(json& j, const MetaDataObject& p);


/*If json Data Object is System
 * sets:
 *      first: light ears
 *      second: 10^n
 * type: suns count
 * Planet & asteroids count: other objects
 */