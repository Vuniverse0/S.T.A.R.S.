#include "Handler.h"
int main()
{
    while (Handler::window().isOpen()) {
        Handler::gHandler.update();
    }
    return 0;
}