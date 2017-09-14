option(PSYCHIC_COLOR_BUILD_TESTS "Build PsychicColor tests?" ON)
add_feature_info("tests" PSYCHIC_COLOR_BUILD_TESTS "Test Suite")

if (PSYCHIC_COLOR_BUILD_TESTS)
    ExternalProject_Add(psychic-color-catch
        GIT_REPOSITORY https://github.com/philsquared/Catch.git
        GIT_TAG master
        CMAKE_ARGS "-DNO_SELFTEST=YES"
    )

    set(CATCH_INCLUDE_DIRS ${CMAKE_CURRENT_BINARY_DIR}/psychic-color-catch-prefix/src/catchlib/single_include)

    add_executable(psychic_color_tests
        main.cpp
        spaces/gray.cpp
        spaces/rgb.cpp
        spaces/argb.cpp
        spaces/hex.cpp
    )
    target_include_directories(psychic_color_tests PUBLIC ${CATCH_INCLUDE_DIRS} ${PSYCHIC_COLOR_INCLUDE_DIRS})
    target_link_libraries(psychic_color_tests psychic-color)

    add_dependencies(psychic_color_tests psychic-color-catch)
    add_dependencies(psychic_color_tests psychic-color)
endif()
