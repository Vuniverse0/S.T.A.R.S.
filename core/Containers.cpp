//
// Created by vuniverse on 11/3/21.
//

#include "Containers.h"


LIST_INIT(Button);
LIST_INIT(Orbit);
LIST_INIT(Entry);
LIST_INIT(Gui);

std::vector<Containers::drawer*> Containers::base{
    LISTING(Orbit),
    LISTING(Entry),
    LISTING(Gui),
    LISTING(Button)
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
        x->handle();
    }
}
