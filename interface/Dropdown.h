#pragma once

#include "Gui.h"
#include "Panel.h"
#include "Group.h"


class Dropdown  {
    Direction m_direction{None};
    Group_I& m_group;
public:
    Dropdown(Direction direction, Group_I& a_group);
};
//Suggestive::Suggestive() : m_list{ this, &Suggestive::handle } { Traceable::Insert(m_list); }