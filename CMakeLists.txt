cmake_minimum_required(VERSION 3.16)
project(space)

set(CMAKE_CXX_STANDARD 20)

add_executable(space main.cpp Animation.cpp Animation.h typedefs_and_globals.h Handler.cpp Handler.h literals.cpp Entry.cpp Entry.h)
target_link_libraries(space  sfml-graphics sfml-window sfml-system)