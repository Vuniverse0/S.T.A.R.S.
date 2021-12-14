#include "Handler.h"
#include "Metadata.h"
#include <fstream>
#include "Loader.h"


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
    Loader::load(Stars::Black);
    //MetaDataBody body;
    json j;
    //to_json(j["System"][0], obj);
    o<<j;
    o.close();
    return 0;
}