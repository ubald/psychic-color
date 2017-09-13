option(PSYCHIC_COLOR_BUILD_TESTS "Build PsychicColor tests?" ON)
add_feature_info("tests" PSYCHIC_COLOR_BUILD_TESTS "Test Suite")

if (PSYCHIC_COLOR_BUILD_TESTS)
    ExternalProject_Add(catchlib
        GIT_REPOSITORY git@github.com:philsquared/Catch.git
        GIT_TAG master
        INSTALL_COMMAND ""
        )

    set(CATCH_INCLUDE_DIRS ${CMAKE_CURRENT_BINARY_DIR}/catchlib-prefix/src/catchlib/single_include)

    add_executable(psychic_color_tests
        ${PSYCHIC_COLOR_SOURCES}
        main.cpp
        gray.cpp
        rgb.cpp
        argb.cpp
        hex.cpp
    )
    target_include_directories(psychic_color_tests PUBLIC ${CATCH_INCLUDE_DIRS} ${PSYCHIC_COLOR_INCLUDE_DIRS})
    add_dependencies(psychic_color_tests catchlib)
endif()
