//
// Created by vuniverse on 11/3/21.
//

#pragma once

#include "../utility/typedefs_and_globals.h"
#include "../primitives/Entry.h"


class Gui : public Entry{
    static std::vector<Gui*> m_all;
public:
    Gui(const std::string&, frames, pixels);
    Gui(const std::string&, frames, pixels, pixels);
    Gui(const std::string&);
    ~Gui() override;

    virtual sf::Texture* getAttach();
};