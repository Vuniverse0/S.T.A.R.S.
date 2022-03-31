//
// Created by vuniverse on 10/22/21.
//

#include "Core.h"
#include "../interface/Interfaces.h"

float_t Handler::x_ratio = //1600 / GAME_MAKER_SCREEN_WIDTH,
       static_cast<float_t>(sf::VideoMode::getFullscreenModes()[0].width) / GAME_MAKER_SCREEN_WIDTH,
Handler::y_ratio = //1000 / GAME_MAKER_SCREEN_HEIGHT;
        static_cast<float_t>(sf::VideoMode::getFullscreenModes()[0].height) / GAME_MAKER_SCREEN_HEIGHT;
Handler Handler::gHandler{};
sf::RenderWindow Handler::m_window(//{1600,1000},
        sf::VideoMode::getFullscreenModes()[0],
        "Surviving Try Around Remote Stars",//sf::Style::Default, sf::ContextSettings(0,0,8));
        sf::Style::Fullscreen, sf::ContextSettings(0,0,8));
float_t Handler::m_alpha{};
sf::Clock Handler::clock{};
bool Handler::m_IsPaused = false;
Handler::Handler() noexcept
{
    set_fps(DEFAULT_FPS);
}

Handler::~Handler()
{
    //TODO erase all for Containers
}
void Handler::handle(LeftCenterPanel& panel)
{
    sf::Event event{};
    while (m_window.pollEvent(event))
    {
        panel.handle(event);
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
                //panel.handle(event);
                break;
            case sf::Event::MouseMoved:
                //(LeftCenterPanel::button0).Suggestive::handle(event);
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
    static sf::Time update_time_fix = sf::milliseconds(1000/60);
    static sf::Sprite sprite;
    //static Animation animation("/home/vuniverse/Downloads/358540927.png",sprite,100,100,600);
    //static Animation animation("/home/vuniverse/CLionProjects/space/resources/celestial_bodies/stars/blue/1871631401.png",sprite,200,200,600);
    //m_star.setAnimation(animation);
    //static Orbit orbit(200);
    sprite.setOrigin(local_center(&sprite));
    sprite.setScale(0.9,0.9);
    //orbit.move(window_center(window()));
    update_time += clock.getElapsedTime();
    while (last_update_time > m_time_per_frame)
    {
        last_update_time -= m_time_per_frame;
        m_window.clear();
        handle(LeftCenterPanel::panel);
        if (update_time >= update_time_fix) {
            //Containers::handleAll<System>((update_time.asMilliseconds()));
            update_time = sf::Time::Zero;
            event();
            //sprite.setPosition(orbit.getWay(1));
            LeftCenterPanel::panel.handle();
            //Containers::handleAll<Entry>();
            //m_alpha = 0.1f * update_time_fix.asMilliseconds();
            //animation.play(0.1f * update_time_fix.asMilliseconds(), true);
        }
        //Containers::drawAll<Entry>();
        LeftCenterPanel::panel.draw();

        m_window.display();
    }
    last_update_time += clock.restart();
}

void Handler::set_fps(const frames& a_fps)
{
    m_window.setFramerateLimit(a_fps + 5 );
    m_time_per_frame = sf::milliseconds(1000 / a_fps);
}

void Handler::input(const sf::Keyboard::Key& key, const bool& isPressed)
{

}

void Handler::pause_switch()
{
    m_IsPaused = !m_IsPaused;
    std::cout<<"pause"<<std::endl;
}

sf::RenderWindow& Handler::window()
{
    return m_window;
}

