#pragma once

#include "../utility/typedefs_and_globals.h"
#include "../primitives/Entry.h"
#include "../interface/LeftCenterPanel.h"


struct Handler {//singleton
private:
    sf::RenderWindow m_window;
    sf::Time m_time_per_frame{}, m_alpha{};
    bool m_IsPaused{false};

public:
    static Handler* gHandler;
    Handler();

    sf::RenderWindow& window();

    sf::Clock clock{};
    float_t x_ratio, y_ratio;
    float_t alpha();

    void pause_switch();
    void handle(Entry& panel);
    void update();
    void event();
    void set_fps(const frames&);
    ~Handler();
};