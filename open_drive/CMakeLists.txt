if (BUILD_GENERATE_OPEN_DRIVE)
    add_subdirectory(generate_open_drive)
endif()

install(DIRECTORY data/ DESTINATION data/)