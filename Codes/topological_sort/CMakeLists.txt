project(topological_sort_test)

add_executable(${PROJECT_NAME} 
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kahns_algorithm.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dfs_reverse.cpp)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})