option(PSYCHIC_COLOR_BUILD_TESTS "Build Psychic Color tests?" ON)
add_feature_info("tests" PSYCHIC_COLOR_BUILD_TESTS "Test Suite")

if (PSYCHIC_COLOR_BUILD_TESTS)
    ExternalProject_Add(psychic-color-catch
        GIT_REPOSITORY https://github.com/philsquared/Catch.git
        GIT_TAG master
        CMAKE_ARGS "-DNO_SELFTEST=YES"
        INSTALL_COMMAND ""
    )

    set(CATCH_INCLUDE_DIRS ${CMAKE_CURRENT_BINARY_DIR}/psychic-color-catch-prefix/src/psychic-color-catch/single_include)

    add_executable(psychic-color-tests
        main.cpp
        spaces/gray.cpp
        spaces/rgb.cpp
        spaces/argb.cpp
        spaces/hex.cpp
    )
    target_include_directories(psychic-color-tests PUBLIC ${CATCH_INCLUDE_DIRS} ${PSYCHIC_COLOR_INCLUDE_DIRS})
    target_link_libraries(psychic-color-tests psychic-color)

    add_dependencies(psychic-color-tests psychic-color-catch)
    add_dependencies(psychic-color-tests psychic-color)
endif()
