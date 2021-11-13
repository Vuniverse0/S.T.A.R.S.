//
// Created by vuniverse on 11/3/21.
//

#include "Containers.h"


LIST_INIT(Button);

std::vector<Containers::uniq> Containers::base{};

void Containers::init()
{
    LISTING(Button);
}

void Containers::drawAll()
{
    for(auto& x : base)
        (*x)->drawe();
}

Containers::drawer *Containers::uniq::operator*()
{
    return m_drawer;
}

Containers::uniq::~uniq()
{
    delete m_drawer;
}