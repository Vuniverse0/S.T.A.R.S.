//
// Created by vuniverse on 11/21/21.
//

#include "LeftCenterPanel.h"
#include "../core/Handler.h"


Dashboard LeftCenterPanel::dashboard(Anchor::CenterLeft,
                           "/home/vuniverse/CLionProjects/space/resources/interface/PNG/MainPanel04.png");
Button LeftCenterPanel::button0("/home/vuniverse/CLionProjects/space/resources/icons/main/research.png",
        no_callback);
Button LeftCenterPanel::button1("/home/vuniverse/CLionProjects/space/resources/icons/main/map.png",
        no_callback);
Button LeftCenterPanel::button2("/home/vuniverse/CLionProjects/space/resources/icons/main/resources.png",
        no_callback);
Button LeftCenterPanel::button3("/home/vuniverse/CLionProjects/space/resources/icons/main/space-shuttle.png",
        no_callback);
Button LeftCenterPanel::button4("/home/vuniverse/CLionProjects/space/resources/icons/main/radar-dish.png",
        no_callback);
Button LeftCenterPanel::button5("/home/vuniverse/CLionProjects/space/resources/icons/main/vortex.png",
        no_callback);
Button LeftCenterPanel::button6("/home/vuniverse/CLionProjects/space/resources/icons/main/pause.png",
       Handler::pause_switch);

LeftCenterPanel::LeftCenterPanel()
{
    dashboard.scale(0.7 * Handler::x_ratio,1.75 * Handler::y_ratio);
    dashboard.locateLeftCenterPanel(button0);
    dashboard.locateLeftCenterPanel(button1);
    dashboard.locateLeftCenterPanel(button2);
    dashboard.locateLeftCenterPanel(button3);
    dashboard.locateLeftCenterPanel(button4);
    dashboard.locateLeftCenterPanel(button5);
    dashboard.locateLeftCenterPanel(button6);
}
