//
// Created by vuniverse on 11/3/21.
//

#pragma once

#include "../utility/typedefs_and_globals.h"
#include "../primitives/Entry.h"


class Gui : public Entry{
public:
    Gui(const std::string&, frames, pixels);
    Gui(const std::string&, frames, pixels, pixels);
    Gui(const std::string&);
    ~Gui() override = default;
    sf::Texture* getAttach();
    virtual bool isGui()const final;
    using Entry::isAnimated;
};