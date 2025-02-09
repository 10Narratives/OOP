find_package(Catch2 2 REQUIRED)

add_executable(work_tests work_tests.cpp)
target_link_libraries(work_tests student_work Catch2::Catch2)

add_executable(stack_tests stack_tests.cpp)
target_link_libraries(stack_tests student_work Catch2::Catch2)
