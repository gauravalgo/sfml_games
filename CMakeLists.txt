cmake_minimum_required(VERSION 3.0)

project(my_first_game)

add_executable(my_first_game main.cpp)

install(TARGETS my_first_game RUNTIME DESTINATION bin)
