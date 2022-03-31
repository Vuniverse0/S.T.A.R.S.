#include "LeftCenterPanel.h"
#include "Panel.h"
#include "Corner.h"


LeftCenterPanel LeftCenterPanel::panel{};

LeftCenterPanel::LeftCenterPanel() : Entry(EMPTY)
{
    dashboard.sprite().setPosition(Corner::ship(Anchor::CenterLeft, dashboard.sprite()));
    Panel::set_separator(15.f);
    Panel::group<Vertical>({dashboard.sprite().getGlobalBounds().left + dashboard.sprite().getGlobalBounds().width / 2.f,
           dashboard.sprite().getGlobalBounds().top+dashboard.sprite().getGlobalBounds().height/2.f},
                           button0, button1, button2, button3, button4, button5, button6);
}

void LeftCenterPanel::draw()
{
    dashboard.draw();
    button0.draw();
    button1.draw();
    button2.draw();
    button3.draw();
    button4.draw();
    button5.draw();
    button6.draw();
}

void LeftCenterPanel::handle()
{
    dashboard.handle();
    static auto hand{[](Entry* ent){ent->handle();}};
    m_group | hand;
}

void LeftCenterPanel::handle(sf::Event &event)
{
    button0.handle(event);
    button1.handle(event);
    button2.handle(event);
    button3.handle(event);
    button4.handle(event);
    button5.handle(event);
    button6.handle(event);
}