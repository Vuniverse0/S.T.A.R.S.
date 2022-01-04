//
// Created by vuniverse on 11/24/21.
//

#pragma once

#include "../core/Metadata.h"
#include "typedefs_and_globals.h"


auto random_int{
    [](int start, int end)->int
    {
        return (binominal_float(start/10.f, end/10.f, 0.5)*10);
    }
};

auto asteroids_body{
    []()->MetaDataBody
    {
        MetaDataBody temp;
        temp.spin = binominal_float(0.1f, 2.f, 0.5);
        temp.speed = binominal_float(0.1f, 1.f, 0.5);
        return{};
    }
};

auto planet_body{
    []()->MetaDataBody {
        MetaDataBody temp;
        temp.bsize = binominal_float(0.1f, 2.f, 0.2);
        if (temp.bsize < 1.f) {
            temp.spin = binominal_float(0.1f, 2.f, 0.8);// animation
            temp.speed = binominal_float(0.1f, 1.f, 0.5);
        }
        else {
            temp.spin = binominal_float(0.1f, 2.f, 0.4); // animation
            temp.speed = binominal_float(0.1f, 1.f, 0.2);
        }
        temp.direction = !(binominal_int(1, 10, 0.5) <= 5);
        temp.spin_direction = !(binominal_int(1, 10, 0.5) <= 5);
        return temp;
    }
};

auto moon_body{
    []()->MetaDataBody
    {
        MetaDataBody temp = planet_body();

        //temp.speed /= 10.f;
        //temp.spin /= 10.f;

        temp.bsize /= 10.f;
        return temp;
    }
};

const auto star_body{
    []()->MetaDataBody
    {
        MetaDataBody temp;
        temp.bsize = binominal_float(2.f, 5.f, 0.5);
        temp.speed = binominal_float(0.1f, 1.f, 0.2);
        temp.spin = binominal_float(0.1f, 2.f, 0.2);
        temp.direction = (binominal_int(1, 10, 0.5) <= 5);
        temp.spin_direction = false;
        return temp;
    }
};