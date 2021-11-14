//
// Created by vuniverse on 10/22/21.
//

#include "Handler.h"
#include "Containers.h"
#include "Orbit.h"

float_t Handler::x_ratio =
        static_cast<float_t>(sf::VideoMode::getFullscreenModes()[0].width) / GAME_MAKER_SCREEN_WIDTH,
Handler::y_ratio =
        static_cast<float_t>(sf::VideoMode::getFullscreenModes()[0].height) / GAME_MAKER_SCREEN_HEIGHT;
Handler Handler::gHandler{};
sf::RenderWindow Handler::m_window(
        sf::VideoMode::getFullscreenModes()[0],
        "Surviving Try Around Remote Stars",
        sf::Style::Fullscreen, sf::ContextSettings(0,0,8));
sf::Clock Handler::clock{};
Handler::Handler() noexcept
{
    set_fps(DEFAULT_FPS);
}

Handler::~Handler()
{
    Containers::listButton.clear();
}

void Handler::handle()
{
    sf::Event event{};
    while (m_window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                m_window.close();
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

void Handler::event()
{

}

void Handler::update()
{
    static sf::Time last_update_time = sf::Time::Zero;
    static sf::Time update_time = sf::Time::Zero;
    static sf::Time update_time_fix = sf::microseconds(1000/60);
    static sf::Sprite sprite;
    static Animation animation("/home/vuniverse/Downloads/1976757976.png",sprite,100,163);
    static Orbit orbit(400,400,200,255);
    sprite.setOrigin(local_center(&sprite));
    update_time += clock.getElapsedTime();
    while (last_update_time > m_time_per_frame)
    {
        last_update_time -= m_time_per_frame;
        m_window.clear();
        handle();
        if(update_time >= update_time_fix) {
            update_time = sf::Time::Zero;
            event();
            sprite.setPosition(orbit.getWay());
        }
        animation.play(0.3f*m_time_per_frame.asMilliseconds());
        render();
        orbit.draw(m_window);
        m_window.draw(sprite);
        m_window.display();
    }
    last_update_time += clock.restart();
}

void Handler::set_fps(const frames& a_fps)
{
    m_window.setFramerateLimit(a_fps+5);
    m_time_per_frame = sf::milliseconds(1000 / a_fps);
}

void Handler::render()
{
    Containers::drawAll();
}

void Handler::input(const sf::Keyboard::Key& key, const bool& isPressed)
{

}

void Handler::pause_switch()
{
    m_IsPaused = !m_IsPaused;
}

sf::RenderWindow& Handler::window()
{
    return m_window;
}

