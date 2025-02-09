cmake_minimum_required(VERSION 3.16)

file(GLOB
        Sources "source/*.cpp"
        Includes "include/*.h"
)
add_library(map STATIC ${Sources} ${Includes})
target_include_directories(map PUBLIC include)
target_link_libraries(map PUBLIC placeables objects)