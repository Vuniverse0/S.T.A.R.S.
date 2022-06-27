#include "Game.h"
#include "Handler.h"
#include "../interface/Panel.h"


Ui Ui::ui{};
Word Word::word{};
Game Game::game{};



void Game::draw()
{
    if ( !handler ) {
        std::cout << "Game: No Handler, gHandler default";
        handler = Handler::gHandler;
    }
    if ( !setup ) {
        if (!word)
            word = &Word::word;
        if (!word->handler)
            word->handler = handler;
        if (!gui)
            gui = &Ui::ui;
        if (!gui->handler)
            gui->handler = handler;
        setup = true;
    }
    word->draw();
    gui->draw();
}

void Ui::draw()
{
    if ( !handler ) {
        std::cerr << "Ui: No Handler";
        return;
    }
    uiChanged = true;
    if ( !uiChanged )
        return;
    else
        uiChanged = false;
    //states can be changed there

    //Group<Gui, 1> basic_gui{*leftCenterPanel};
    //handler->draw_ui(basic_gui, states);
    handler->draw_ui(leftCenterPanel, states);

    //handler->draw(what, ui_states);
}

void Ui::use()
{
    uiChanged = true;
}

void Ui::handle(const sf::Event& event)
{
    switch(event.type){
        case sf::Event::MouseButtonReleased:
        case sf::Event::MouseMoved:
            leftCenterPanel->handle(event);
            break;
        default:
            std::cerr << "Ui Handle: wrong event passed" << std::endl;
            break;
    }
}

void Ui::disable_basic_ui() { basic_ui_active = false; }

void Ui::enable_basic_ui() { basic_ui_active = true; }


void Word::draw()
{
    if ( !handler ) {
        std::cerr << "Word: No Handler";
        return;
    }
    //states can be changed there

    //handler->draw(what, states);
}