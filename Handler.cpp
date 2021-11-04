//
// Created by vuniverse on 10/22/21.
//

#include "Handler.h"
#include "Containers.h"


float_t Handler::x_ratio = GAME_MAKER_SCREEN_WIDTH, Handler::y_ratio = GAME_MAKER_SCREEN_WIDTH;

Handler::Handler( sf::RenderWindow& window, sf::VideoMode mode):
        m_window(window)
{
    x_ratio = static_cast<float_t>(mode.width) / GAME_MAKER_SCREEN_WIDTH;
    y_ratio = static_cast<float_t>(mode.height)  / GAME_MAKER_SCREEN_HEIGHT;
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
                //Containers::listButton[0]->checkClick({event.mouseMove.x, event.mouseMove.y});
                break;
            case sf::Event::MouseMoved:
                //Containers::listButton[0]->isOnMouse({event.mouseMove.x, event.mouseMove.y});
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
//    if(Containers::listButton[0]->isOnClick()){
//        Containers::listButton[0]->move(400,400);
//    }
}

void Handler::update()
{
    static sf::Time last_update_time = sf::Time::Zero;
    static sf::Clock clock;
    while (last_update_time > m_time_per_frame)
    {
        last_update_time -= m_time_per_frame;
        handle();
        m_window.clear();
        Containers::drawAll(Containers::listButton);
    }
    last_update_time += clock.restart();
}

void Handler::set_fps(const frames& a_fps)
{
    m_window.setFramerateLimit(a_fps);
    m_time_per_frame = sf::milliseconds(1000 / a_fps);
    Settings::g_fps=a_fps;
}

void Handler::render()
{

}

void Handler::input(const sf::Keyboard::Key& key, const bool& isPressed)
{

}

void Handler::pause_switch()
{
    m_IsPaused = !m_IsPaused;
}

sf::RenderWindow &Handler::window()
{
    return m_window;
}

