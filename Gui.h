//
// Created by vuniverse on 11/3/21.
//

#pragma once

#include "typedefs_and_globals.h"
#include "Entry.h"


class Gui : public Entry{

public:
    Gui(cords unnamed, cords unnamed1);
    virtual bool isGui()const;
    using Entry::isAnimated;
};