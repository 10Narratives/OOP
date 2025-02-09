cmake_minimum_required(VERSION 3.26)
project(lab3)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -lsfml-window -lsfml-graphics -lsfml-system -fsanitize=thread")

add_compile_options(-fsanitize=thread -g)
add_link_options(-fsanitize=thread)

add_subdirectory(entities)
add_subdirectory(tests)
add_subdirectory(views)
add_subdirectory(app)

add_executable(lab3 main.cpp)
target_link_libraries(lab3 App placeables)

add_executable(timeTest timeTest.cpp)
target_link_libraries(timeTest App placeables)
