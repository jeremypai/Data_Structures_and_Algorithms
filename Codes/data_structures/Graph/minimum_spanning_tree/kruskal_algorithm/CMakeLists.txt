project(kruskal_algorithm_test)

add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kruskal_algorithm.cpp)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../union_find)

target_link_libraries(${PROJECT_NAME}
    PRIVATE GTest::gtest_main)
    
gtest_discover_tests(${PROJECT_NAME})