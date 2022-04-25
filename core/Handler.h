#pragma once

#include "../utility/typedefs_and_globals.h"
#include "../primitives/Entry.h"
#include "../interface/LeftCenterPanel.h"


struct Handler {//singleton
private:
    Handler() noexcept ;
    sf::RenderWindow m_window;
    sf::Time m_time_per_frame;
    static bool m_IsPaused;
public:
    static sf::Clock clock;
    static Handler gHandler;
    static float_t x_ratio, y_ratio;
    static const sf::RenderWindow& window();
    static float_t m_alpha;
    void pause_switch();
    void handle(Entry& panel);
    void update();
    void event();
    void set_fps(const frames&);
    void input(const sf::Keyboard::Key& key, const bool& isPressed);
    ~Handler();
};