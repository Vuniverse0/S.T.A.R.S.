//
// Created by vuniverse on 11/14/21.
//

#include "Dashboard.h"

sf::Vector2f Corner::LeftTop = {};
sf::Vector2f Corner::RightTop;
sf::Vector2f Corner::LeftBottom;
sf::Vector2f Corner::RightBottom;

Dashboard::Dashboard(cords a_x, cords a_y, const std::string& a_string, transformator a_transformator):
                     Gui( a_x, a_y, a_string,  a_transformator)
{

}
