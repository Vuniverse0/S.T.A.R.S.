#pragma once
#include "Entry.h"

struct Sprite : Entry {
    using Entry::Entry;
    void handle() override;
    ~Sprite() override = default;
};