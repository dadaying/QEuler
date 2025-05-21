cmake_minimum_required(VERSION 3.10)

project(QEuler CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${BUILD_DIR})
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/${BUILD_DIR}/${INSTALL_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include(cmake/cmake_util.cmake)

if (ENABLE_TEST)
    install(FILES ./scripts/run_test.sh DESTINATION scripts)
endif()

add_subdirectory(common)
add_subdirectory(third_party)

if (ENABLE_EXPERIMENTAL)
    add_subdirectory(experimental)
endif()

add_subdirectory(opendrive)