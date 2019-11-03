cmake_minimum_required(VERSION 3.0)

project(my_first_game)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(my_first_game main.cpp)
target_link_libraries(my_first_game sfml-graphics sfml-audio)
install(TARGETS my_first_game RUNTIME DESTINATION bin)
