//
// Created by vuniverse on 11/22/21.
//

#pragma once

#include "../objects/Galaxy.h"


class Create {
    static std::vector<Entry*> render;
public:
    static Entry* create(const Body& a_body);
};