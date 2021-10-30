//
// Created by vuniverse on 10/22/21.
//

#include "Handler.h"

std::vector<Entry*> Handler::entry_list{nullptr};
std::vector<Entry*> Handler::gui_list{nullptr};

Handler::Handler( sf::RenderWindow& window, sf::VideoMode mode):
    window(window),
    x_ratio{mode.width / GAME_MAKER_SCREEN_WIDTH},
    y_ratio{mode.height / GAME_MAKER_SCREEN_HEIGHT}
{


}

void Handler::handle() {
    sf::Event event{};
    while (window.pollEvent(event))
    {

    }
}

void Handler::update()
{
    static sf::Time last_update_time = sf::Time::Zero;
    static sf::Clock clock;
    while (last_update_time > time_per_frame)
    {
        last_update_time -= time_per_frame;
        handle();
    }
    last_update_time += clock.restart();
}

void Handler::set_fps(frames fps)
{
    window.setFramerateLimit(fps);
    time_per_frame = sf::milliseconds(1000/fps);
}

void Handler::render() {
    for(auto x : Handler::entry_list){
        x->draw(window);
    }
    for(auto x: Handler::gui_list){
        x->draw(window);
    }
}

void Handler::input(sf::Keyboard::Key key, bool isPressed) {

}

void Handler::pause_switch() {
    paused = !paused;
}
