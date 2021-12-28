//
// Created by vuniverse on 11/21/21.
//

#include "System.h"
#include "../core/Loader.h"
#include "../utility/random_body.h"

System::System(const json& j) :
    Entry("null.png"),
    m_star(MetaDataObject::from_json(j), MetaDataBody::from_json(j))
{

}

System::System() :
    Entry("null.png"),
    m_star(Stars::Blue, {{},{}}, Loader::load(Stars::Blue))
{

}

System::~System()
{

}

void System::handle()
{
    m_star.handle();
}

void System::draw()
{
    m_star.draw();
}