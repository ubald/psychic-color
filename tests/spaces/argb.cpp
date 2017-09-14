#include <cmath>
#include "catch.hpp"
#include <psychic-color/spaces/ARGB.hpp>
#include <iostream>

using namespace psychic_color;

TEST_CASE("ARGB") {

    SECTION("initializes") {
        ARGB argb{0.1f, 0.2f, 0.3f, 0.4f};
        REQUIRE(argb.getAlpha() == 0.1f);
        REQUIRE(argb.getRed() == 0.2f);
        REQUIRE(argb.getGreen() == 0.3f);
        REQUIRE(argb.getBlue() == 0.4f);
    }

    SECTION("sets") {
        ARGB argb{0.1f, 0.2f, 0.3f, 0.4f};
        argb.setAlpha(0.5f);
        argb.setRed(0.6f);
        argb.setGreen(0.7f);
        argb.setBlue(0.8f);
        REQUIRE(argb.getAlpha() == 0.5f);
        REQUIRE(argb.getRed() == 0.6f);
        REQUIRE(argb.getGreen() == 0.7f);
        REQUIRE(argb.getBlue() == 0.8f);
    }

    SECTION("gets color") {
        ARGB argb{0.1f, 0.2f, 0.3f, 0.4f};
        REQUIRE(argb.getColor() == (
            (static_cast<unsigned int>(std::round(0.1f * 255.0f)) << 24)
            | (static_cast<unsigned int>(std::round(0.2f * 255.0f)) << 16)
            | (static_cast<unsigned int>(std::round(0.3f * 255.0f)) << 8)
            | static_cast<unsigned int>(std::round(0.4f * 255.0f))
        ));
    }

    SECTION("sets color") {
        ARGB argb{};
        argb.setColor((
                          (static_cast<unsigned int>(std::round(0.1f * 255.0f)) << 24)
                          | (static_cast<unsigned int>(std::round(0.2f * 255.0f)) << 16)
                          | (static_cast<unsigned int>(std::round(0.3f * 255.0f)) << 8)
                          | static_cast<unsigned int>(std::round(0.4f * 255.0f))
                      ));
        REQUIRE(argb.getAlpha() == Approx(0.1f).epsilon(0.5f / 255.0f));
        REQUIRE(argb.getRed() == Approx(0.2f).epsilon(0.5f / 255.0f));
        REQUIRE(argb.getGreen() == Approx(0.3f).epsilon(0.5f / 255.0f));
        REQUIRE(argb.getBlue() == Approx(0.4f).epsilon(0.5f / 255.0f));
    }

    SECTION("create from another ARGB") {
        ARGB argb1{0.1f, 0.2f, 0.3f, 0.4f};
        ARGB argb2{argb1};

        REQUIRE(argb2.getAlpha() == 0.1f);
        REQUIRE(argb2.getRed() == 0.2f);
        REQUIRE(argb2.getGreen() == 0.3f);
        REQUIRE(argb2.getBlue() == 0.4f);
    }

    SECTION("create from another ARGB (verify)") {
        ARGB argb1{0.1f, 0.2f, 0.3f, 0.4f};
        ARGB argb2{argb1};

        argb2.setAlpha(0.5f);
        argb2.setRed(0.6f);
        argb2.setGreen(0.7f);
        argb2.setBlue(0.8f);

        REQUIRE(argb1.getAlpha() == 0.1f);
        REQUIRE(argb1.getRed() == 0.2f);
        REQUIRE(argb1.getGreen() == 0.3f);
        REQUIRE(argb1.getBlue() == 0.4f);

        REQUIRE(argb2.getAlpha() == 0.5f);
        REQUIRE(argb2.getRed() == 0.6f);
        REQUIRE(argb2.getGreen() == 0.7f);
        REQUIRE(argb2.getBlue() == 0.8f);
    }

    SECTION("interpolate") {
        //ARGB argb0.1f{};
        //ARGB argb0.2f{0.1f0.0f,0.2f0.0f,0.3f0.0f, 0.4f0.0f};
        //ARGB argb0.3f = argb0.1f.interpolate(argb0.2f);
        //REQUIRE(argb0.3f.getAlpha() == 0.5f);
        //REQUIRE(argb0.3f.getRed() == 0.1f0.0f);
        //REQUIRE(argb0.3f.getGreen() == 0.1f0.5f);
        //REQUIRE(argb0.3f.getBlue() == 0.2f0.0f);
    }
}
