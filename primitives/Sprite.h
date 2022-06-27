#pragma once
#include "Entry.h"

template<typename T = Entry>
struct Sprite : T {
    using T::T;
    void handle() override {};
    ~Sprite() override = default;
};