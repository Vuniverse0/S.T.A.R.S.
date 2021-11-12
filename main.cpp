#include <SFML/Graphics.hpp>
#include "typedefs_and_globals.h"
#include "Handler.h"
#include "Animation.h"
#include "Button.h"


int main()
{
    Settings::g_settings.antialiasingLevel = 8;
    sf::RenderWindow window(
            sf::VideoMode::getFullscreenModes()[0],
            "Surviving Try Around Remote Stars",
            sf::Style::Fullscreen,Settings::g_settings);
    Settings::g_window = &*&window;
    window.setFramerateLimit(DEFAULT_FPS+5);
    Handler handler(window, sf::VideoMode::getFullscreenModes()[0]);

    float radius_x = 450.0f * 0.7f;
    float radius_y = radius_x * 0.6f;
    int quality = 170;

    sf::ConvexShape ellipse;
    ellipse.setPointCount(quality);

    for (unsigned int i =0; i < quality; ++i) {
        float rad = (360.0f/static_cast<float>(quality*i))/(360.0f/static_cast<float>(M_PI)/2.0f);
        float x = cos(rad-0.1f)*radius_x;
        float y = sin(rad+0.3f)*radius_y;

        ellipse.setPoint(i,sf::Vector2f(x,y));
    }
    ellipse.setOutlineThickness(2);
    ellipse.setOutlineColor(sf::Color(88,136,255,50));
    ellipse.setFillColor(sf::Color(0,0,0,0));
    ellipse.setPosition(400,400);

    Button button(400, 400,
            "/home/vuniverse/Downloads/VovasProject/icons/research/instruments.png", Animation::default_transformator);
    unsigned short i=0;
    while (window.isOpen()) {
            if(i==quality){i=0;}
            auto point = ellipse.getPoint(i);
            button.move(point.x+400,point.y+400);
            i++;
        handler.update();

        window.draw(ellipse);
        window.display();

    }
    Settings::g_window = nullptr;
    return 0;
}