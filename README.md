# WIP

# Psychic Color

A C++ library for color conversion and color scheme generation. 

It is based on [hxColorToolkit](https://github.com/andyli/hxColorToolkit) 
which in turn was based on [colortoolkit](http://code.google.com/p/colortoolkit/) with lots of bug fixes and enhancements.

## What's with the name?

This is intended to be part of a future larger project so it is named according to that projet's name. I intend to make
sources available as much as possible for all of the project's parts in the form of libraries like this.

## Usage

The library needs a C++17 compiler and CMake 3.24 or newer. Either add it to your CMake build and link the
`psychic-color::psychic-color` target, which brings the include directory and the C++17 requirement along with it,
or just copy the headers and sources to your project and include them however you want.

As a submodule:

```cmake
add_subdirectory(lib/psychic-color)
target_link_libraries(my-target PRIVATE psychic-color::psychic-color)
```

Or with FetchContent:

```cmake
include(FetchContent)
FetchContent_Declare(psychic-color
    GIT_REPOSITORY https://github.com/ubald/psychic-color.git
    GIT_TAG master
)
FetchContent_MakeAvailable(psychic-color)
target_link_libraries(my-target PRIVATE psychic-color::psychic-color)
```

Headers are included from the repository root, e.g. `#include <psychic-color/spaces/HSL.hpp>`. The library is
static unless `BUILD_SHARED_LIBS` is on, and is compiled as position-independent code so it can go into a shared library.
When included from another project, the tests and the warning flags stay off unless you turn on
`PSYCHIC_COLOR_BUILD_TESTS` or `PSYCHIC_COLOR_WARNINGS`.

## Building and testing

```sh
cmake -B build
cmake --build build -j"$(nproc)"
ctest --test-dir build
```

The tests use [Catch2](https://github.com/catchorg/Catch2) v3. An installed Catch2 3.x is used if CMake can find it,
otherwise v3.16.1 is downloaded at configure time (pass `-DCMAKE_DISABLE_FIND_PACKAGE_Catch2=ON` to always download it).
The test executable can also be run directly, as `./build/tests/psychic-color-tests`.

## Color spaces

They can be found inside the package `spaces`. All of them extend the base class `spaces.Color`.

* `CMYK` 4-channel [CMYK](http://en.wikipedia.org/wiki/CMYK_color_model) color space with each channel in [0.0f,1.0f].
* `Gray` A single channel gray-scale color in [0.0f,1.0f]. Any color given will be converted to gray-scale.
* `Hex` A simple wrapper of color value in hex(eg. `0xFFFFCCCC`). Its `alpha`, `red`, `green`, `blue` extract the corresponding value to `unsigned int`.
* `HSB` 3-channel [HSB](http://en.wikipedia.org/wiki/HSL_and_HSV) color space with ranges [0.0f,1.0f], [0.0f,1.0f], [0.0f,1.0f].
* `HSL` 3-channel [HSL](http://en.wikipedia.org/wiki/HSL_and_HSV) color space with ranges [0.0f,1.0f], [0.0f,1.0f], [0.0f,1.0f].
* `RGB` Normal 3-channel [RGB](http://en.wikipedia.org/wiki/RGB_color_space) color space with each channel in [0.0f,1.0f]. Unlike `Hex`, its properties(`red`, `green`, `blue`) are stored as `float` for precise calculation.
* `ARGB` 4-channel ARGB color space with each channel in [0.0f,1.0f]. It is a sub-class of `RGB` with an additional `alpha` value that defaults to 1.0f.

### Not yet ported (Not very useful for GUI work anyway)

* `Lab` 3-channel [Lab](http://en.wikipedia.org/wiki/Lab_color_space) color space with ranges [0,100], [-128,127], [-128,127].
* `XYZ` 3-channel [XYZ](http://en.wikipedia.org/wiki/CIE_1931_color_space) color space with ranges [0,95.047], [0,100], [0,108.883].
* `YUV` 3-channel [YUV](http://en.wikipedia.org/wiki/YUV) color space with each channel in [0,255].

All channel values are clamped to their possible min/max, except hue values of `HSB` and `HSL` are looped inside 0-360 (`color.hue = -10; trace(color.hue); //350`).

## Color schemes

Color scheme is basically a set of colors, constructed according to [color theory](http://en.wikipedia.org/wiki/Color_theory).

The classes can be found inside the package `hxColorToolkit.schemes`. All of them implement the interface `hxColorToolkit.schemes.ColorScheme`.

* `Analogous`
* `Complementary`
* `Compound`
* `FlippedCompound`
* `Monochrome`
* `SplitComplementary`
* `Tetrad`
* `Triad`
