#include "LeftCenterPanel.h"
#include "../core/Handler.h"


inline namespace LeftCenterPanelButtons{
    Changer l0{[](){std::cout<<"button0";}};
    Changer l1{[](){std::cout<<"button1";}};
    Changer l2{[](){std::cout<<"button2";}};
    Changer l3{[](){std::cout<<"button3";}};
    Changer l4{[](){std::cout<<"button4";}};
    Changer l5{[](){std::cout<<"button5";}};
    Changer l6{[](){std::cout<<"button6";}};

    Button button0{LeftCenterPanelButtons::l0, "../resources/icons/main/research.png"};
    Button button1{LeftCenterPanelButtons::l1, "../resources/icons/main/map.png"};
    Button button2{LeftCenterPanelButtons::l2, "../resources/icons/main/resources.png"};
    Button button3{LeftCenterPanelButtons::l3, "../resources/icons/main/space-shuttle.png"};
    Button button4{LeftCenterPanelButtons::l4, "../resources/icons/main/radar-dish.png"};
    Button button5{LeftCenterPanelButtons::l5, "../resources/icons/main/vortex.png"};
    Button button6{LeftCenterPanelButtons::l6, "../resources/icons/main/pause.png"};

    Group m_group{button0, button1, button2, button3, button4, button5, button6};
    Group m_group2{button1, button2};
    Unfold fold{ Direction::Right,button0, m_group2, 15.f * VALUABLE_RATIO};
};

LeftCenterPanel LeftCenterPanel::panel{};

void LeftCenterPanel::draw()
{
    dashboard.draw();
    m_group | drew;
}

void LeftCenterPanel::handle()
{
    dashboard.handle();
    m_group | hand;
    fold.handle();
}

void LeftCenterPanel::handle(Event event)
{
    static auto handew{ [&](Entry* ent){ ent->handle(event);} };
    m_group | handew;
    fold.handle(event);
}

LeftCenterPanel::LeftCenterPanel() : Entry(EMPTY),
                   dashboard{"../resources/interface/PNG/MainPanel04.png",
            0.7f * Handler::x_ratio, 1.75f * Handler::y_ratio}
{
    dashboard.sprite().setPosition(Corner::ship(Anchor::CenterLeft, dashboard.sprite()));
    Place::group<Vertical>(
            {dashboard.sprite().getGlobalBounds().left + dashboard.sprite().getGlobalBounds().width / 2.f,
                dashboard.sprite().getGlobalBounds().top+dashboard.sprite().getGlobalBounds().height/2.f},
                15.f * VALUABLE_RATIO, m_group);
}
