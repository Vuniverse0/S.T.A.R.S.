#pragma once
#include "Entry.h"

struct Sprite : Entry {
    void handle() override;
    using Entry::Entry;
    ~Sprite() override = default;
};