//
// Created by vuniverse on 11/3/21.
//

#include "Containers.h"


LIST_INIT(Button);
LIST_INIT(Orbit);

std::vector<Containers::drawer*> Containers::base{
    LISTING(Button),
    LISTING(Orbit)
};

void Containers::drawAll()
{
    for (auto& x : base) {
        x->drawe();
    }
}

void Containers::handleAll()
{
    for (auto& x : base) {
        x->drawe();
    }
}
