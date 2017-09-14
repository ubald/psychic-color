# WIP

# Psychic Color

[![Build Status](https://travis-ci.org/ubald/psychic-color.svg?branch=master)](https://travis-ci.org/ubald/psychic-color)

A C++ library for color conversion and color scheme generation. 

It is based on [hxColorToolkit](https://github.com/andyli/hxColorToolkit) 
which in turn was based on [colortoolkit](http://code.google.com/p/colortoolkit/) with lots of bug fixes and enhancements.

## What's with the name?

This is intended to be part of a future larger project so it is named according to that projet's name. I intend to make
sources available as much as possible for all of the project's parts in the form of libraries like this.

## Usage

Clone as a submodule and either use `add_subdirectory` in CMake and then add `${PSYCHIC_UI_INCLUDE_DIRS}` to your include
directories, or just copy the headers and source to your project and include them however you want.

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
