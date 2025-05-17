cmake_minimum_required(VERSION 3.10)
project(QEuler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test test.cc)

target_include_directories(test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../..)

add_executable(vec2_test vec2_test.cc)
target_include_directories(vec2_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../third_party/googletest/include)
target_include_directories(vec2_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_link_directories(vec2_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../third_party/googletest/lib)
target_link_libraries(vec2_test gtest)

MESSAGE(STATUS "Inlcude directory: ${CMAKE_CURRENT_SOURCE_DIR}/../..")