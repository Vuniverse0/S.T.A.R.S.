//
// Created by vuniverse on 10/22/21.
//

#include "Handler.h"

std::vector<Entry*> Handler::entry_list{};
std::vector<Entry*> Handler::gui_list{};

Handler::Handler( sf::RenderWindow& window, sf::VideoMode mode):
    window(window),
    x_ratio{mode.width / GAME_MAKER_SCREEN_WIDTH},
    y_ratio{mode.height / GAME_MAKER_SCREEN_HEIGHT}
{
    set_fps(DEFAULT_FPS);
}

void Handler::handle() {
    sf::Event event{};
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                break;
            case sf::Event::LostFocus:
                break;
            case sf::Event::GainedFocus:
                break;
            case sf::Event::TextEntered:
                break;
            case sf::Event::KeyPressed:
                break;
            case sf::Event::KeyReleased:
                break;
            case sf::Event::MouseWheelMoved:
                break;
            case sf::Event::MouseWheelScrolled:
                break;
            case sf::Event::MouseButtonPressed:
                break;
            case sf::Event::MouseButtonReleased:

                break;
            case sf::Event::MouseMoved:
                break;
            case sf::Event::MouseEntered:
                break;
            case sf::Event::MouseLeft:
                break;
            case sf::Event::JoystickButtonPressed:
                break;
            case sf::Event::JoystickButtonReleased:
                break;
            case sf::Event::JoystickMoved:
                break;
            case sf::Event::JoystickConnected:
                break;
            case sf::Event::JoystickDisconnected:
                break;
            case sf::Event::TouchBegan:
                break;
            case sf::Event::TouchMoved:
                break;
            case sf::Event::TouchEnded:
                break;
            case sf::Event::SensorChanged:
                break;
            case sf::Event::Count:
                break;
        }
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

void Handler::set_fps(const frames& fps)
{
    window.setFramerateLimit(fps);
    time_per_frame = sf::milliseconds(1000/fps);
    Settings::g_fps=fps;
}

void Handler::render() {
    for(auto x : Handler::entry_list){
        x->draw(window);
    }
    for(auto x: Handler::gui_list){
        x->draw(window);
    }
}

void Handler::input(const sf::Keyboard::Key& key, const bool& isPressed) {

}

void Handler::pause_switch() {
    paused = !paused;
}
