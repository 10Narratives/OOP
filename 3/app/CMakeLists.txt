cmake_minimum_required(VERSION 3.16)

file(GLOB
        Sources "source/*.cpp"
        Includes "include/*.h"
)
add_library(App STATIC ${Sources} ${Includes})
target_include_directories(App PUBLIC include)
target_link_libraries(App PUBLIC placeables views map)