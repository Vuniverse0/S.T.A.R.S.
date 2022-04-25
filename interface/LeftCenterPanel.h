#pragma once

#include "Button.h"
#include "../primitives/Sprite.h"
#include "../primitives/Group.h"
#include "Corner.h"


class LeftCenterPanel : public Entry {
    Sprite dashboard;
    LeftCenterPanel();
public:
    static LeftCenterPanel panel;
    void draw();
    void handle() override;
    void handle( Event ) override;
};