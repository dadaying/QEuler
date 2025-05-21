if (BUILD_GENERATE_OPENDRIVE)
    add_subdirectory(generate_opendrive)
endif()

install(DIRECTORY data/ DESTINATION data/)