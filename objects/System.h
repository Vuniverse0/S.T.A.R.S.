//
// Created by vuniverse on 11/21/21.
//

#pragma once

#include "Star.h"


class System : public Entry {
    static uint16_t m_idGenerator;

    Star m_star; //Or multi star, its delegate
    static std::vector<System*> m_all;
    static System* m_current;
public:
    System();
    explicit System(const json&);
    //~System() override ;

    //void handle() override ;
    //void draw() override ;
};