//
// Created by vuniverse on 11/3/21.
//

#include "Containers.h"


std::vector<Containers::drawer*> Containers::m_handle_base{};
std::vector<Containers::drawer*> Containers::m_drawe_base{};

void Containers::drawAll()
{
    for (auto& x : m_drawe_base) {
        x->drawe();
    }
}

void Containers::handleAll()
{
    for (auto& x : m_handle_base) {
        x->handle();
    }
}
