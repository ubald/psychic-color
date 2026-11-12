include(FetchContent)
FetchContent_Declare(Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.16.1
    GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS 3
)
FetchContent_MakeAvailable(Catch2)

add_executable(psychic-color-tests
    psychic_color.cpp
    spaces/gray.cpp
    spaces/rgb.cpp
    spaces/argb.cpp
    spaces/hex.cpp
    spaces/hsb.cpp
    spaces/hsl.cpp
    schemes/complementary.cpp
)
target_link_libraries(psychic-color-tests PRIVATE psychic-color::psychic-color Catch2::Catch2WithMain)
psychic_color_warnings(psychic-color-tests)

add_test(NAME psychic-color-tests COMMAND psychic-color-tests)
