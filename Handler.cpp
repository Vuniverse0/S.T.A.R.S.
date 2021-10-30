//
// Created by vuniverse on 10/22/21.
//

#include "Handler.h"

Handler::Handler( sf::RenderWindow& window, sf::VideoMode mode):
window(window),
x{mode.width / GAME_MAKER_SCREEN_WIDTH},
y{mode.height / GAME_MAKER_SCREEN_HEIGHT}
{


}