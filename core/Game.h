#pragma once

#include "../primitives/Group.h"


struct Handler;
struct Entry;
struct Gui;
struct Panel;
struct Button;

struct Ui{
    Handler* handler = nullptr;

    IGroup<Gui>* gui = nullptr;
    IGroup<Button>* FreeButtons = nullptr;

    Panel* leftCenterPanel = nullptr;

    Gui* additional_gui = nullptr;

    void draw();
    void use();

    void disable_basic_ui();
    void enable_basic_ui();

    void handle(const sf::Event& event);

    static Ui ui;
    sf::RenderStates ui_states = sf::RenderStates::Default;
    sf::RenderStates states = sf::RenderStates::Default;
private:
    bool uiChanged = false; // true when events or process animation
    bool basic_ui_active = true;
    Ui() = default;
};

struct Word{
    Handler* handler = nullptr;

    IGroup<Entry>* FreeEntries = nullptr;

    void draw();

    static Word word;
    sf::RenderStates states = sf::RenderStates::Default;
private:
    Word() = default;
};

struct Game {
    Handler* handler = nullptr;

    Ui* gui = nullptr;
    Word* word = nullptr;

    void draw();

    static Game game;
private:
    bool setup = false;
    Game() = default;
};