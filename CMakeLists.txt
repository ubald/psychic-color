cmake_minimum_required(VERSION 3.4)
project(psychic-color)

set(CMAKE_CXX_STANDARD 14)

include(ExternalProject)
include(FeatureSummary)

set(PSYCHIC_COLOR_SOURCES
    psychic-color/spaces/Gray.cpp
    psychic-color/spaces/Hex.cpp
    psychic-color/spaces/RGB.cpp
    psychic-color/spaces/ARGB.cpp
    psychic-color/spaces/HSB.cpp
    psychic-color/spaces/HSL.cpp
    psychic-color/schemes/Analogous.cpp
    psychic-color/schemes/Analogous.hpp)

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
