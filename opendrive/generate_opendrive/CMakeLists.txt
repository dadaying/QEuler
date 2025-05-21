add_executable(generate_opendrive generate_opendrive_main.cc)
# TODO(liying): Remove relative directories.
target_include_directories(generate_opendrive PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../third_party/tinyxml2/include)
target_link_directories(generate_opendrive PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../third_party/tinyxml2/lib)
target_link_libraries(generate_opendrive tinyxml2)

install(TARGETS generate_opendrive DESTINATION bin)
install(FILES ../../scripts/run_generate_opendrive.sh DESTINATION scripts)