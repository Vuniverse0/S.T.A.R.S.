//
// Created by vuniverse on 11/21/21.
//

#include "System.h"


System::System(const json& j) :
    Entry("null.png"),
    m_star(MetaDataObject::from_json(j[0]), MetaDataBody::from_json(j[0]))
{

}
/*
System::System() :
    Entry("null.png"),
    m_star()
{

}
*/