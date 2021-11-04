//
// Created by vuniverse on 11/3/21.
//

#pragma once

#include "typedefs_and_globals.h"
#include "Entry.h"


class Gui : public Entry{
public:
    Gui(cords, cords, const std::string&, frames, pixels, transformator);
    Gui(cords, cords, cords, cords, const std::string&, frames, pixels, transformator);
    Gui(cords, cords, const std::string&, transformator);
    ~Gui() override = default;
    virtual bool isGui()const;
    using Entry::isAnimated;
};