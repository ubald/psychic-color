cmake_minimum_required(VERSION 3.24...4.4)
project(psychic-color VERSION 0.1.0 LANGUAGES CXX)

option(PSYCHIC_COLOR_BUILD_TESTS "Build the Psychic Color tests" ${PROJECT_IS_TOP_LEVEL})
option(PSYCHIC_COLOR_WARNINGS "Compile Psychic Color with -Wall -Wextra" ${PROJECT_IS_TOP_LEVEL})

add_library(psychic-color
    psychic-color/css_colors.hpp
    psychic-color/PsychicColor.hpp
    psychic-color/PsychicColor.cpp
    psychic-color/spaces/Color.hpp
    psychic-color/spaces/Gray.hpp
    psychic-color/spaces/Gray.cpp
    psychic-color/spaces/Hex.hpp
    psychic-color/spaces/Hex.cpp
    psychic-color/spaces/RGB.hpp
    psychic-color/spaces/RGB.cpp
    psychic-color/spaces/ARGB.hpp
    psychic-color/spaces/ARGB.cpp
    psychic-color/spaces/HSB.hpp
    psychic-color/spaces/HSB.cpp
    psychic-color/spaces/HSL.hpp
    psychic-color/spaces/HSL.cpp
    psychic-color/schemes/ColorScheme.hpp
    psychic-color/schemes/ColorWheelScheme.hpp
    psychic-color/schemes/Analogous.hpp
    psychic-color/schemes/Complementary.hpp
    psychic-color/schemes/Compound.hpp
    psychic-color/schemes/FlippedCompound.hpp
    psychic-color/schemes/Monochrome.hpp
    psychic-color/schemes/SplitComplementary.hpp
    psychic-color/schemes/Tetrad.hpp
    psychic-color/schemes/Triad.hpp
)
add_library(psychic-color::psychic-color ALIAS psychic-color)

target_include_directories(psychic-color PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(psychic-color PUBLIC cxx_std_17)
set_target_properties(psychic-color PROPERTIES POSITION_INDEPENDENT_CODE ON)

function(psychic_color_warnings target)
    if (PSYCHIC_COLOR_WARNINGS)
        if (MSVC)
            target_compile_options(${target} PRIVATE /W4)
        else ()
            target_compile_options(${target} PRIVATE -Wall -Wextra)
        endif ()
    endif ()
endfunction()

psychic_color_warnings(psychic-color)

if (PSYCHIC_COLOR_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif ()
