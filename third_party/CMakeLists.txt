# TODO(liying): Use option to choose the third-party libraries to be installed.
file(GLOB googletest_libs ${CMAKE_CURRENT_SOURCE_DIR}/googletest/lib/*.a)
install(FILES ${googletest_libs} DESTINATION third_party)

file(GLOB tinyxml2_libs ${CMAKE_CURRENT_SOURCE_DIR}/tinyxml2/lib/*.a)
install(FILES ${tinyxml2_libs} DESTINATION third_party)