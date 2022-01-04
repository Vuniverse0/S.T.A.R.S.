//
// Created by vuniverse on 11/21/21.
//

#pragma once

#include "Star.h"


class System : public Entry {
    friend Containers;
    static uint16_t m_idGenerator;
    Star m_star; //Or multi star, its delegate
    inline static std::vector<System*> m_all{};
    static System* m_current;
public:
    System();
    explicit System(const json&);
    ~System() override ;

    void handle(const sf::Int32& time);
    void handle() override ;
    void draw() override ;
};