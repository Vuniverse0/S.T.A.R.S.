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
        #core/Metadata.cpp
        core/Resource.cpp
        core/Save.cpp
        interface/Corner.cpp
        core/Loader.cpp
        interface/Button.cpp
        primitives/Vectorized.cpp
        interface/Panel.cpp core/Game.h core/Game.cpp interface/Directions.cpp)
target_compile_options(space PUBLIC "-D _DEBUG")
target_link_libraries(space  sfml-graphics sfml-window sfml-system)
