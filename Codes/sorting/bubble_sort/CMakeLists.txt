project(bubble_sort_test)

add_executable(${PROJECT_NAME} bubble_sort.cpp)

target_link_libraries(${PROJECT_NAME}
    PRIVATE GTest::gtest_main)

gtest_discover_tests(${PROJECT_NAME})