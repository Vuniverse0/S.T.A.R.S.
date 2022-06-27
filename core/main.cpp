#include "Handler.h"
#include "Game.h"
#include "../interface/Panel.h"


int main()
{
    Handler handler;
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    Button button0{+[](){std::cout<<"button0";}, "../resources/icons/main/research.png"};
    Button button1{+[](){std::cout<<"button2";}, "../resources/icons/main/map.png"};
    Button button2{+[](){std::cout<<"button3";}, "../resources/icons/main/resources.png"};
    Button button3{+[](){std::cout<<"button4";}, "../resources/icons/main/space-shuttle.png"};
    Button button4{+[](){std::cout<<"button5";}, "../resources/icons/main/radar-dish.png"};
    Button button5{+[](){std::cout<<"button6";}, "../resources/icons/main/vortex.png"};
    Button button6{+[](){std::cout<<"button7";}, "../resources/icons/main/pause.png"};

    Group<Button, 7> m_group{button0, button1, button2, button3, button4, button5, button6};
    Panel leftCenterPanel(m_group,
                          Sprite<Gui>{"../resources/interface/PNG/MainPanel04.png",
                                 0.7f, 1.75f});

    Ui::ui.leftCenterPanel = &leftCenterPanel;

    while (handler.isOpen()) {
        sf::Time deltaTime = clock.restart();
        //std::cout<< deltaTime.asSeconds() <<"\n";
        timeSinceLastUpdate += deltaTime;
        while (timeSinceLastUpdate > handler.TimePerFrame()) {
            timeSinceLastUpdate -= handler.TimePerFrame();
            //std::cout<<"hail"<<std::endl;
            handler.process_events();  //process events
            handler.update(deltaTime); //process process_events of game
        }
        handler.render();
    }
    return 0;
}

#if 0
std::ofstream o("/home/vuniverse/Documents/pretty.json");
#include "Metadata.h"
#include <fstream>
#include "Loader.h"
#include "../objects/System.h"
#include "../utility/random_body.h"
    MetaDataObject obj{
        Body::System,
        {static_cast<unsigned int>(21)},
        {{0},{0}},
        "none.png",
        6,
        "name"
    };
    //Loader::load(Stars::Black);
    //MetaDataBody body;
    json j;
    //to_json(j["System"][0], obj);
    o<<j;
    o.close();
    for (auto i = 0 ; i < 100; ++i) {
        //std::cout << "float " << RANDOM_N_AFTER_POINT(2,20,10.f)<< std::endl;
        //std::cout << "int "<< ((int) binominal_int(1, 10, 0.5)) << std::endl;
    }
#endif