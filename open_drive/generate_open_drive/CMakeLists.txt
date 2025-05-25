add_executable(generate_open_drive_main generate_open_drive_main.cc)
# TODO(liying): Remove relative directories.
target_include_directories(generate_open_drive_main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../third_party/tinyxml2/include)
target_link_directories(generate_open_drive_main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../third_party/tinyxml2/lib)
target_link_libraries(generate_open_drive_main tinyxml2)

target_include_directories(generate_open_drive_main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../third_party/sqlite/include)
target_link_directories(generate_open_drive_main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../third_party/sqlite/lib)
target_link_libraries(generate_open_drive_main sqlite3)

install(TARGETS generate_open_drive_main DESTINATION bin)
install(FILES ../../scripts/run_generate_open_drive.sh DESTINATION scripts)