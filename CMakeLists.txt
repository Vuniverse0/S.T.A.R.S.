cmake_minimum_required(VERSION 3.16)
project(space)

set(CMAKE_CXX_STANDARD 20)
add_executable(space core/main.cpp primitives/Animation.cpp primitives/Animation.h utility/typedefs_and_globals.h core/Handler.cpp core/Handler.h utility/literals.cpp primitives/Entry.cpp primitives/Entry.h interface/Button.cpp interface/Button.h interface/Gui.cpp interface/Gui.h core/Containers.cpp core/Containers.h objects/Orbit.cpp objects/Orbit.h interface/Dashboard.cpp interface/Dashboard.h interface/LeftCenterPanel.cpp interface/LeftCenterPanel.h interface/RigthBottomMesenger.cpp interface/RigthBottomMesenger.h interface/Message.cpp interface/Message.h)
target_link_libraries(space  sfml-graphics sfml-window sfml-system)