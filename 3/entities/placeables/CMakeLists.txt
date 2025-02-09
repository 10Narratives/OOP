cmake_minimum_required(VERSION 3.16)

file(GLOB
        Sources "source/*.cpp"
        Includes "include/*.h"
)
add_library(placeables STATIC ${Sources} ${Includes})
target_include_directories(placeables PUBLIC include)
target_link_libraries(placeables PUBLIC objects)