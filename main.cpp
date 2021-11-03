#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdio>
#include "typedefs_and_globals.h"
#include "Handler.h"
#include "Animation.h"
#include "Button.h"
#define PI 3.1415926535898
sf::Texture generateTexture(const std::string& texture, int size, int offset)//offset by number of frames
{
    sf::Texture texture_out;
    texture_out.loadFromFile(texture,sf::IntRect(offset*size, 0, size, size));
    return texture_out;
}

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel=8;
    sf::RenderWindow window(
            sf::VideoMode::getFullscreenModes()[0],
            "Surviving Try Around Remote Stars",
            sf::Style::Fullscreen,settings);
    window.setFramerateLimit(DEFAULT_FPS);
    Handler handler(window, sf::VideoMode::getFullscreenModes()[0]);

    double radius_x=450;
    double radius_y=340;
    double quality=170;

    sf::ConvexShape ellipse;
    ellipse.setPointCount(quality);

    for(unsigned short i=0;i<quality;++i){
        double rad = (360.0/quality*i)/(360/PI/2);
        double x = cos(rad-0.1)*radius_x;
        double y = sin(rad+0.3)*radius_y;

        ellipse.setPoint(i,sf::Vector2f(x,y));
    };
    ellipse.setPosition(400,400);
    ellipse.setOutlineThickness(2);
    ellipse.setOutlineColor(sf::Color(88,136,255,50));
    ellipse.setFillColor(sf::Color(0,0,0,0));
   // ellipse.rotate(-20);
    sf::Texture texture;
    texture.loadFromFile("/home/vuniverse/Downloads/VovasProject/icons/research/instruments.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    Button button(100,100,sprite);
    float angle = 20;
    ellipse.move(100,0);
    while (window.isOpen()) {
        handler.update();

//        double rad = (360.0/quality*i)/(360/PI/2);
//        double x1 = cos(rad)*radius_x;
//        double y1 = sin(rad)*radius_y;
        window.clear();
        //ellipse.setRotation(angle);
        window.draw(ellipse);

        window.display();
    }
    std::cout << angle;
    return 0;
}