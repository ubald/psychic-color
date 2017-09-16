cmake_minimum_required(VERSION 3.4)
project(psychic-color)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -stdlib=libc++")
endif()

include(ExternalProject)
include(FeatureSummary)

set(PSYCHIC_COLOR_SOURCES
    psychic-color/css_colors.hpp
    psychic-color/PsychicColor.hpp
    psychic-color/PsychicColor.cpp
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


add_library(psychic-color STATIC
    ${PSYCHIC_COLOR_SOURCES}
)

set(PSYCHIC_COLOR_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
set(PSYCHIC_COLOR_LIBRARIES ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_STATIC_LIBRARY_PREFIX}psychic-color${CMAKE_STATIC_LIBRARY_SUFFIX})

set(PSYCHIC_COLOR_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR} PARENT_SCOPE)
set(PSYCHIC_COLOR_SOURCES ${PSYCHIC_COLOR_SOURCES} PARENT_SCOPE)
set(PSYCHIC_COLOR_LIBRARIES ${PSYCHIC_COLOR_LIBRARIES} PARENT_SCOPE)

# TESTS
add_subdirectory(tests)
