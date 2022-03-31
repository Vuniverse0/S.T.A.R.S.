#pragma once

#include "Button.h"
#include "../primitives/Sprite.h"
#include "Group.h"

namespace LeftCenterPanelButtons{
    Changer l0{[](){std::cout<<"button0";}};
    Changer l1{[](){std::cout<<"button1";}};
    Changer l2{[](){std::cout<<"button2";}};
    Changer l3{[](){std::cout<<"button3";}};
    Changer l4{[](){std::cout<<"button4";}};
    Changer l5{[](){std::cout<<"button5";}};
    Changer l6{[](){std::cout<<"button6";}};
};

class LeftCenterPanel : Entry {
    Sprite dashboard{"../resources/interface/PNG/MainPanel04.png", 0.7, 1.75};
    Button button0{LeftCenterPanelButtons::l0, "../resources/icons/main/research.png"};
    Button button1{LeftCenterPanelButtons::l1, "../resources/icons/main/map.png"};
    Button button2{LeftCenterPanelButtons::l2, "../resources/icons/main/resources.png"};
    Button button3{LeftCenterPanelButtons::l3, "../resources/icons/main/space-shuttle.png"};
    Button button4{LeftCenterPanelButtons::l4, "../resources/icons/main/radar-dish.png"};
    Button button5{LeftCenterPanelButtons::l5, "../resources/icons/main/vortex.png"};
    Button button6{LeftCenterPanelButtons::l6, "../resources/icons/main/pause.png"};
    Group<7> m_group{button0, button1, button2, button3, button4, button5, button6};
    LeftCenterPanel();
public:
    static LeftCenterPanel panel;
    void draw();
    void handle() override ;
    void handle(sf::Event& event);
};