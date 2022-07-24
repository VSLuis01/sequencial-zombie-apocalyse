cmake_minimum_required(VERSION 3.22)
project(MPI_Zombie_Apocalypse)

set(CMAKE_CXX_STANDARD 23)

add_executable(MPI_Zombie_Apocalypse main.cpp World.cpp World.h Cell.cpp Cell.h Apocalypse.cpp Apocalypse.h Entity.cpp Entity.h Human.cpp Human.h Zombie.cpp Zombie.h)
target_link_libraries(MPI_Zombie_Apocalypse sfml-graphics sfml-window sfml-system)