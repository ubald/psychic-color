cmake_minimum_required(VERSION 3.4)
project(psychic-color)

set(CMAKE_CXX_STANDARD 14)

include(ExternalProject)
include(FeatureSummary)

set(PSYCHIC_COLOR_SOURCES
    psychiccolor/spaces/Gray.cpp
    psychiccolor/spaces/Hex.cpp
    psychiccolor/spaces/RGB.cpp
    psychiccolor/spaces/ARGB.cpp
    psychiccolor/spaces/HSB.cpp
    psychiccolor/spaces/HSL.cpp
)

add_library(psychic-color STATIC
    ${PSYCHIC_COLOR_SOURCES}
)

set(PSYCHIC_COLOR_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(PSYCHIC_COLOR_LIBRARIES ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_STATIC_LIBRARY_PREFIX}psychic-color${CMAKE_STATIC_LIBRARY_SUFFIX})

set(PSYCHIC_COLOR_SOURCES PARENT_SCOPE)

set(PSYCHIC_COLOR_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR})
set(PSYCHIC_COLOR_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR} PARENT_SCOPE)

# TESTS
add_subdirectory(tests)
