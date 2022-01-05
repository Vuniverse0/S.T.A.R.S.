#include "Handler.h"
#include "Metadata.h"
#include <fstream>
#include "Loader.h"
#include "../objects/System.h"
#include "../utility/random_body.h"


int main()
{
    while (Handler::window().isOpen()) {
        Handler::gHandler.update();
    }
    std::ofstream o("/home/vuniverse/Documents/pretty.json");
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
        std::cout << "int "<< ((int) binominal_int(1, 10, 0.5)) << std::endl;
    }
    return 0;
}