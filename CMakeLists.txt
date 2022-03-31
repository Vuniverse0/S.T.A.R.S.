cmake_minimum_required(VERSION 3.16)
project(space)

set(CMAKE_CXX_STANDARD 20)
add_executable(space
        core/main.cpp
        primitives/Animation.cpp
        core/Handler.cpp
        utility/literals.cpp
        primitives/Entry.cpp
        interface/Gui.cpp
        objects/Orbit.cpp
        interface/LeftCenterPanel.cpp
        interface/Message.cpp
        core/Metadata.cpp
        core/Resource.cpp
        core/Save.cpp
        interface/Corner.cpp
        core/Loader.cpp
        primitives/Animated.cpp
        interface/Button.cpp
        interface/Panel.cpp
        primitives/Sprite.cpp
        interface/Dropdown.cpp interface/Group.h)
#add_executable(space core/main.cpp primitives/Animation.cpp primitives/Animation.h utility/typedefs_and_globals.h core/Handler.cpp core/Handler.h utility/literals.cpp primitives/Entry.cpp primitives/Entry.h interface/Button.h interface/Gui.cpp interface/Gui.h core/Containers.h objects/Orbit.cpp objects/Orbit.h interface/Dashboard.cpp interface/Dashboard.h interface/LeftCenterPanel.cpp interface/LeftCenterPanel.h interface/RigthBottomMesenger.cpp interface/RigthBottomMesenger.h interface/Message.cpp interface/Message.h objects/Planet.cpp objects/Planet.h objects/Asteroids.cpp objects/Asteroids.h objects/Star.cpp objects/Star.h objects/System.cpp objects/System.h objects/Galaxy.cpp objects/Galaxy.h objects/Objects.h core/Core.h interface/Interfaces.h core/Metadata.cpp core/Metadata.h core/Resource.cpp core/Resource.h core/Save.cpp core/Save.h objects/Moon.cpp objects/Moon.h utility/random_body.h interface/Corner.cpp interface/Corner.h core/overloaded.h core/Loader.cpp core/Loader.h primitives/Animated.cpp primitives/Animated.h)
target_link_libraries(space  sfml-graphics sfml-window sfml-system)