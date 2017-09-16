option(PSYCHIC_COLOR_BUILD_TESTS "Build Psychic Color tests?" ON)
add_feature_info("tests" PSYCHIC_COLOR_BUILD_TESTS "Test Suite")

if (PSYCHIC_COLOR_BUILD_TESTS)

    if (NOT TARGET catch)
        ExternalProject_Add(catch
            GIT_REPOSITORY https://github.com/philsquared/Catch.git
            GIT_TAG master
            PREFIX "${CMAKE_BINARY_DIR}/catch"
            CMAKE_ARGS "-DNO_SELFTEST=YES"
            INSTALL_COMMAND ""
            )

        set(CATCH_INCLUDE_DIRS ${CMAKE_BINARY_DIR}/catch/src/catch/single_include CACHE INTERNAL "Global catch include")
    endif()

    add_executable(psychic-color-tests
        main.cpp
        spaces/gray.cpp
        spaces/rgb.cpp
        spaces/argb.cpp
        spaces/hex.cpp
        spaces/hsb.cpp
        schemes/complementary.cpp psychic_color.cpp)
    target_include_directories(psychic-color-tests PUBLIC ${CATCH_INCLUDE_DIRS} ${PSYCHIC_COLOR_INCLUDE_DIRS})
    target_link_libraries(psychic-color-tests psychic-color)

    add_dependencies(psychic-color-tests psychic-color)
    add_dependencies(psychic-color-tests catch)
endif()
