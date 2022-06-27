#include "LeftCenterPanel.h"
#include "../core/Handler.h"

#if 0

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

LeftCenterPanel::LeftCenterPanel() : Panel(EMPTY)
{
    static Group m_group{button0, button1, button2, button3, button4, button5, button6};
    sprite().setPosition(Corner::ship(Anchor::CenterLeft, dashboard.sprite()));
    Place::group<Vertical, 7>(
            {dashboard.sprite().getGlobalBounds().left + dashboard.sprite().getGlobalBounds().width / 2.f,
                dashboard.sprite().getGlobalBounds().top+dashboard.sprite().getGlobalBounds().height/2.f},
                15.f * VALUABLE_RATIO, m_group);
}
#endif