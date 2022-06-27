#pragma once

#include "../utility/typedefs_and_globals.h"
#include "../primitives/Group.h"


struct Entry;
struct Gui;

struct Handler {//singleton
private:
    sf::RenderWindow m_window;
    sf::RenderTexture m_ui;
    sf::Time m_time_per_frame{};
    bool m_IsPaused{false};
public:
    static Handler* gHandler;
    Handler();
    void draw (const Entry* drawable, const sf::RenderStates& states = sf::RenderStates::Default);
    void draw_ui (const Gui* drawable, const sf::RenderStates& states = sf::RenderStates::Default);
    void draw (const IGroup<Entry>& drawable, const sf::RenderStates& states = sf::RenderStates::Default);
    void draw_ui (const IGroup<Gui>& drawable, const sf::RenderStates& states = sf::RenderStates::Default);
    float_t x_ratio, y_ratio;
    static sf::Vector2u getSize();
    static sf::Time TimePerFrame();
    void resume();
    void pause();
    void render();
    void update(sf::Time deltaTime);
    void process_events();
    void set_fps(const frames&);
    static bool isOpen();
    bool exit();
    ~Handler();
};