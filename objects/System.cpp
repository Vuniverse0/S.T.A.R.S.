//
// Created by vuniverse on 11/21/21.
//

#include "System.h"
#include "../core/Loader.h"
#include "../utility/random_body.h"

System::System(const json& j) :
    Entry(EMPTY),
    m_star(MetaDataObject::from_json(j), MetaDataBody::from_json(j))
{
    //std::cerr<<"System SUCCESSFUL↵\n";
    m_all.push_back(this);
}

System::System() :
    Entry(EMPTY),
    m_star(Stars::Blue, {{},{}}, Loader::load(Stars::Blue), 3)
{
    //std::cerr<<"System SUCCESSFUL↵\n";
    m_all.push_back(this);
}

System::~System()
{
    m_all.erase(std::find(m_all.begin(),m_all.end(), this));
}

void System::handle()
{
    m_star.m_handle();
}

void System::handle(const sf::Int32& time)
{
    m_star.handle(time);
}

void System::draw()
{
    m_star.m_draw();
}