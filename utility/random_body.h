//
// Created by vuniverse on 11/24/21.
//

#pragma once

#include "../core/Metadata.h"
#include "typedefs_and_globals.h"


auto asteroids_body{
    []()->MetaDataBody
    {
        MetaDataBody temp;
        temp.spin = binominal(0.1f, 2.f, 0.8);
        temp.speed = binominal(0.1f, 2.f, 0.5);
        return{};
    }
};

auto planet_body{
    []()->MetaDataBody {
        MetaDataBody temp;
        temp.bsize = binominal(0.1f, 2.f, 0.2);
        if (temp.bsize < 1.f) {
            temp.spin = binominal(0.1f, 2.f, 0.8);//animation
            temp.speed = binominal(0.1f, 2.f, 0.5);
        }
        else {
            temp.spin = binominal(0.1f, 2.f, 0.5); //animation
            temp.speed = binominal(0.1f, 2.f, 0.2);
        }
        return temp;
    }
};

auto moon_body{
        []()->MetaDataBody
        {
            MetaDataBody temp = planet_body();
            temp.speed /= 10.f;
            temp.bsize /= 10.f;
            temp.spin /= 10.f; //animation
            return temp;
        }
};

auto star_body{
    []()->MetaDataBody
    {
        MetaDataBody temp;
        temp.bsize = binominal(2.f, 5.f, 0.5);
        temp.speed = binominal(0.1f, 1.f, 0.2);
        temp.spin = binominal(0.1f, 2.f, 0.2); //animation
        return temp;
    }
};


