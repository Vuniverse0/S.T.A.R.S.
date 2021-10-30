//
// Created by vuniverse on 10/27/21.
//

#pragma once

#include "typedefs_and_globals.h"

#define SET_BIT_FIELD(index) void set_bit_field_p##index(bool arg){data.p##index=(arg)?1:0;};
#define GET_BIT_FIELD(index) bool get_bit_field_p##index(){return (data.p##index == 1);};
#define SET_END_GET_DECLARATION(index) GET_BIT_FIELD(index) SET_BIT_FIELD(index)
struct flags{
    union{
        struct {
            uint8_t p0:1;
            uint8_t p1:1;
            uint8_t p2:1;
            uint8_t p3:1;
            uint8_t p4:1;
            uint8_t p5:1;
            uint8_t p6:1;
            uint8_t p7:1;
        };
        uint8_t all = 0;
    }data;
    SET_END_GET_DECLARATION(0);
    SET_END_GET_DECLARATION(1);
    SET_END_GET_DECLARATION(2);
    SET_END_GET_DECLARATION(3);
    SET_END_GET_DECLARATION(4);
    SET_END_GET_DECLARATION(5);
    SET_END_GET_DECLARATION(6);
    SET_END_GET_DECLARATION(7);
};
class Entry {
    cords x,y,z;

};


