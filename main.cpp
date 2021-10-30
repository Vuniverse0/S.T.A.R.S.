#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdio>
#include "typedefs_and_globals.h"
#include "Handler.h"
#include "Animation.h"
#define PI 3.1415926535898
sf::Texture generateTexture(const std::string& texture, int size, int offset)//offset by number of frames
{
    sf::Texture texture_out;
    texture_out.loadFromFile(texture,sf::IntRect(offset*size, 0, size, size));
    return texture_out;
}

int main()
{
    sf::Texture texture=generateTexture("/home/vuniverse/Downloads/start_planet.png",100,49);
    sf::Texture texture2=generateTexture("/home/vuniverse/Downloads/start_planet.png",100,1);
    //texture.loadFromFile("/home/vuniverse/Downloads/start_planet.png",sf::IntRect(0,0,50,10));
    //texture2.loadFromFile("/home/vuniverse/Downloads/start_planet.png",sf::IntRect(100,0,50,100));

    sf::Sprite s1;
    sf::Sprite s2;
    s2.setTexture(texture);
    Animation animation("/home/vuniverse/Downloads/3376286448.png", s1, 200_p, 50_f);
    animation.play();
    sf::ContextSettings settings;
    settings.antialiasingLevel=8;
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Surviving Try Around Remote Stars",sf::Style::Fullscreen,settings);
    for(auto x: sf::VideoMode::getFullscreenModes()){
        std::cout<<x.height<<' '<<x.width<<'\n';
    }
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    window.setFramerateLimit(60);


    double radius_x=150;
    double radius_y=50;
    double quality=70;

    sf::ConvexShape ellipse;
    ellipse.setPointCount(quality);

    for(unsigned short i=0;i<quality;++i){
        double rad = (360.0/quality*i)/(360/PI/2);
        double x = cos(rad)*radius_x;
        double y = sin(rad)*radius_y;

        ellipse.setPoint(i,sf::Vector2f(x,y));
    };
    ellipse.setPosition(400,400);
    ellipse.setOutlineThickness(2);
    ellipse.setOutlineColor(sf::Color(88,136,255,100));
    ellipse.setFillColor(sf::Color(0,0,0,0));

    int x=0;
    bool r=false,l=false;
    s2.move(sf::Vector2f(0,100));
    bool flaggg=true;
    int i=0;
    radius_x=150;
     radius_y=50;
    while (window.isOpen())
    {
        x=0;
        sf::Event event;
        int ch;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed){
                //std::cout<<ch<<std::endl;
                if(event.key.code == sf::Keyboard::Left){
                    l=true;
                } else if (event.key.code == sf::Keyboard::Right){
                    r=true;
                }

            }else if (event.type == sf::Event::KeyReleased){
                //std::cout<<ch<<std::endl;
                if(event.key.code == sf::Keyboard::Left){
                    l=false;
                } else if (event.key.code == sf::Keyboard::Right){
                    r=false;
                }

            }

        }
        if(i>quality){
            i=0;
        }
        double rad = (360.0/quality*i)/(360/PI/2);
        double x1 = cos(rad)*radius_x;
        double y1 = sin(rad)*radius_y;
        i++;
        if(l){
            s2.setTexture(texture2);
            x+=10;
        }else if(r){
            x-=10;
            s2.setTexture(texture);
        }
        if(flaggg) {
            animation.play(0);
            flaggg=!flaggg;
        }else{
            flaggg=!flaggg;
        }
        s1.move(sf::Vector2f(x,0));
        s2.setPosition(sf::Vector2f(x1+400,y1+400));
        std::cout<<x1<<" : "<<y1<<std::endl;
        window.clear();
        window.draw(shape);
        window.draw(ellipse);
        window.draw(s1);
        window.draw(s2);
        window.display();
    }
    return 0;
}