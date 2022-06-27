#pragma once

#include "Panel.h"
#include "../primitives/Sprite.h"
#include "../primitives/Group.h"
#include "Corner.h"


class LeftCenterPanel : public Panel {
    Sprite dashboard;
public:
    Button button0{+[](){std::cout<<"button0";}, "../resources/icons/main/research.png"};
    Button button1{+[](){std::cout<<"button2";}, "../resources/icons/main/map.png"};
    Button button2{+[](){std::cout<<"button3";}, "../resources/icons/main/resources.png"};
    Button button3{+[](){std::cout<<"button4";}, "../resources/icons/main/space-shuttle.png"};
    Button button4{+[](){std::cout<<"button5";}, "../resources/icons/main/radar-dish.png"};
    Button button5{+[](){std::cout<<"button6";}, "../resources/icons/main/vortex.png"};
    Button button6{+[](){std::cout<<"button7";}, "../resources/icons/main/pause.png"};
    //Group m_group{button0, button1, button2, button3, button4, button5, button6};
    void draw();
    void handle() override;
    void handle( Event ) override;

    LeftCenterPanel();
};