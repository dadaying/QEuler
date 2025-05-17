file(GLOB googletest_libs ${CMAKE_CURRENT_SOURCE_DIR}/googletest/lib/*.a)

install(FILES ${googletest_libs} DESTINATION third_party)