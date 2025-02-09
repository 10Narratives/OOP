cmake_minimum_required(VERSION 3.16)

file(GLOB
        Sources "source/*.cpp"
        Includes "include/*.h"
)
add_library(objects STATIC ${Sources} ${Includes})
target_include_directories(objects PUBLIC include)
target_link_libraries(objects PUBLIC placeables)