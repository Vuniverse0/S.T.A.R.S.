#include "Handler.h"
#include "../interface/Gui.h"
#include "Game.h"


Handler* Handler::gHandler { nullptr };

Handler::Handler() noexcept(noexcept(sf::RenderWindow())) :
        m_window(//{1600,1000},
                sf::VideoMode::getFullscreenModes()[0],
                "Surviving Try Around Remote Stars",//sf::Style::Default, sf::ContextSettings(0,0,8));
                sf::Style::Fullscreen, sf::ContextSettings(0,0,8)
                ),
        x_ratio {static_cast<float_t>(sf::VideoMode::getFullscreenModes()[0].width) / GAME_MAKER_SCREEN_WIDTH},
        y_ratio {static_cast<float_t>(sf::VideoMode::getFullscreenModes()[0].height) / GAME_MAKER_SCREEN_HEIGHT}
{
    if(gHandler){
        throw std::runtime_error("Second Handler");
    }
    gHandler = this;
    if ( !m_ui.create(sf::VideoMode::getFullscreenModes()[0].width,
                     sf::VideoMode::getFullscreenModes()[0].height) )
        throw std::runtime_error("Cannot create UI");
    set_fps(DEFAULT_FPS);
}

Handler::~Handler()
{
    gHandler = nullptr;
    //TODO erase all for Containers (hehe i deleted these class)
}

void Handler::update(sf::Time deltaTime)
{
#if 0
    static sf::Time last_update_time = sf::Time::Zero;
    static sf::Time update_time = sf::Time::Zero;
    static sf::Time update_time_fix = sf::milliseconds(1000/60);
    static sf::Sprite sprite;
    //static LeftCenterPanel panel{};
    static Button button0{+[](){std::cout<<"button0";}, "../resources/icons/main/research.png"};
    static Button button1{+[](){std::cout<<"button2";}, "../resources/icons/main/map.png"};
    static Button button2{+[](){std::cout<<"button3";}, "../resources/icons/main/resources.png"};
    static Button button3{+[](){std::cout<<"button4";}, "../resources/icons/main/space-shuttle.png"};
    static Button button4{+[](){std::cout<<"button5";}, "../resources/icons/main/radar-dish.png"};
    static Button button5{+[](){std::cout<<"button6";}, "../resources/icons/main/vortex.png"};
    static Button button6{+[](){std::cout<<"button7";}, "../resources/icons/main/pause.png"};
    static Group<Button, 7> m_group{button0, button1, button2, button3, button4, button5, button6};
    static Panel leftCenterPanel(m_group,
                                 Sprite{"../resources/interface/PNG/MainPanel04.png",
                                        0.7f * Handler::gHandler->x_ratio, 1.75f * Handler::gHandler->y_ratio});

    //static Animation animation("/home/vuniverse/Downloads/358540927.png",sprite,100,100,600);
    //static Animation animation("/home/vuniverse/CLionProjects/space/resources/celestial_bodies/stars/blue/1871631401.png",sprite,200,200,600);
    //m_star.setAnimation(animation);
    //static Orbit orbit(200);
    sprite.setOrigin(local_center(&sprite));
    sprite.setScale(0.9,0.9);
    //orbit.move(window_center(window()));

    update_time += m_alpha;
    while (last_update_time > m_time_per_frame)
    {
        std::cout<< update_time.asMilliseconds()<<std::endl;
        last_update_time -= m_time_per_frame;
        m_window.clear();
        handle(leftCenterPanel);
        if (update_time >= update_time_fix) {
            //Containers::handleAll<System>((update_time.asMilliseconds()));
            update_time = sf::Time::Zero;
           // event();
            //sprite.setPosition(orbit.getWay(1));
            leftCenterPanel.process_events();
            //Containers::handleAll<Entry>();
            //m_alpha = 0.1f * update_time_fix.asMilliseconds();
            //animation.play(0.1f * update_time_fix.asMilliseconds(), true);
        }
        //Containers::drawAll<Entry>();
        leftCenterPanel.draw();

        m_window.display();
    }
    last_update_time += clock.restart();
#endif
}

void Handler::set_fps(const frames& a_fps)
{
    m_window.setFramerateLimit(a_fps + 5 );
    m_time_per_frame = sf::seconds(1.f  / static_cast<float_t>(a_fps));
}


void Handler::resume(){ m_IsPaused = true; }

void Handler::pause(){  m_IsPaused = false; }


bool Handler::exit() { m_window.close(); if ( m_window.isOpen() ) return false; return true; }

sf::Time Handler::TimePerFrame(){return gHandler->m_time_per_frame;}

void Handler::render()
{
    m_window.clear();
    m_ui.clear();

    Game::game.draw();

    m_ui.display();
    m_window.draw(sf::Sprite{m_ui.getTexture()}, Game::game.gui->ui_states);
    m_window.display();
}

void Handler::process_events()
{
    sf::Event event{};
    while ( m_window.pollEvent(event) ) {
        switch (event.type) {
            case sf::Event::Closed:
                exit();
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
                //panel.process_events(event);
                break;
            case sf::Event::MouseMoved:

                //(LeftCenterPanel::button0).Suggestive::process_events(event);
                break;
            case sf::Event::MouseEntered:
                break;
            case sf::Event::MouseLeft:
                pause();
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

void Handler::draw(const Entry* drawable, const sf::RenderStates& states)
{
    drawable->draw(m_window, states);
}

void Handler::draw_ui(const Gui *drawable, const sf::RenderStates &states)
{
    drawable->draw(m_ui, states);
}

bool Handler::isOpen()
{
    return gHandler->m_window.isOpen();
}

sf::Vector2u Handler::getSize()
{
    return gHandler->m_window.getSize();
}

void Handler::draw(const IGroup<Entry> &drawable, const sf::RenderStates &states)
{
    for( auto& item : drawable)
        draw(item, states);
}

void Handler::draw_ui(const IGroup<Gui> &drawable, const sf::RenderStates &states)
{
    for( auto& item : drawable)
        draw_ui(item, states);
}
