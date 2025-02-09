cmake_minimum_required(VERSION 3.16)

file(GLOB
        Sources "source/*.cpp"
        Includes "include/*.h"
)
add_library(views STATIC ${Sources} ${Includes})
target_include_directories(views PUBLIC include)
target_link_libraries(views PUBLIC map)