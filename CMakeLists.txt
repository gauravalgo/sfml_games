cmake_minimum_required(VERSION 3.0)

project(my_first_game)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
find_package(CGAL)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
add_executable(my_first_game main.cpp Game.h Game.cpp)
target_link_libraries(my_first_game sfml-graphics sfml-audio CGAL::CGAL Eigen3::Eigen)
install(TARGETS my_first_game RUNTIME DESTINATION bin)
