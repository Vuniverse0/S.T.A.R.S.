#pragma once

#include "../utility/typedefs_and_globals.h"
#include "../primitives/Entry.h"
#include "Directions.h"

class Panel {
    struct vertical_t{};
    struct horizontal_t{};
    static float_t calc(vertical_t, Entry* ent);
    static float_t calc(horizontal_t, Entry* ent);
    static void placeX(Entry* ent, float_t c, float_t x, float_t& sum_a);
    static void placeY(Entry* ent, float_t c, float_t y, float_t& sum_a);
    static float_t separator;
public:
    Panel() = delete;

    static void set_separator(const decltype(separator) &inp);
    inline static vertical_t vertical{};
    inline static horizontal_t horizontal{};

    template<Orientation O, typename ...Args>
    static void group(sf::Vector2f v, Args& ...args)//[x, c] =  v
    {
        if constexpr(O == Vertical){
            auto&[x, c] =  v;
            float_t sum_a = (calc(vertical, &args) + ... ) / 2.f;
            (placeX(&args, c, x, sum_a), ...);
        }

        if constexpr (O == Horizontal){
            auto&[y, c] =  v;
            float_t sum_a = (calc(horizontal, &args) + ... ) / 2.f;
            (placeY(&args, c, y, sum_a), ...);
        }
    }
};