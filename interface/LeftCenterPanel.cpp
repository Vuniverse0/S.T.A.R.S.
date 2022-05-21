#include "LeftCenterPanel.h"
#include "../core/Handler.h"



void LeftCenterPanel::draw()
{
    static Group m_group{button0, button1, button2, button3, button4, button5, button6};
    Group m_group2{button1, button2};
    Unfold fold{ Direction::Right,button0, m_group2, 15.f * VALUABLE_RATIO};
    dashboard.draw();
    m_group | drew;
}

void LeftCenterPanel::handle()
{
    static Group m_group{button0, button1, button2, button3, button4, button5, button6};
    static Group m_group2{button1, button2};
    static Unfold fold{ Direction::Right,button0, m_group2, 15.f * VALUABLE_RATIO};
    dashboard.handle();
    m_group | hand;
    fold.handle();
}

void LeftCenterPanel::handle(Event event)
{
    static Group m_group{button0, button1, button2, button3, button4, button5, button6};
    static Group m_group2{button1, button2};
    static Unfold fold{ Direction::Right,button0, m_group2, 15.f * VALUABLE_RATIO};
    static auto handew{ [&](Entry* ent){ ent->handle(event);} };
    m_group | handew;
    fold.handle(event);
}

LeftCenterPanel::LeftCenterPanel() : Entry(EMPTY),
                   dashboard{"../resources/interface/PNG/MainPanel04.png",
            0.7f * Handler::gHandler->x_ratio, 1.75f * Handler::gHandler->y_ratio}
{
    static Group m_group{button0, button1, button2, button3, button4, button5, button6};
    dashboard.sprite().setPosition(Corner::ship(Anchor::CenterLeft, dashboard.sprite()));
    Place::group<Vertical>(
            {dashboard.sprite().getGlobalBounds().left + dashboard.sprite().getGlobalBounds().width / 2.f,
                dashboard.sprite().getGlobalBounds().top+dashboard.sprite().getGlobalBounds().height/2.f},
                15.f * VALUABLE_RATIO, m_group);
}
