#include <cmath>
#include "catch.hpp"
#include <psychic_color/spaces/RGB.hpp>
#include <iostream>

using namespace psychic_color;

TEST_CASE("RGB") {

    SECTION("initializes") {
        RGB rgb{0.1f, 0.2f, 0.3f};
        REQUIRE(rgb.getRed() == 0.1f);
        REQUIRE(rgb.getGreen() == 0.2f);
        REQUIRE(rgb.getBlue() == 0.3f);
    }

    SECTION("sets") {
        RGB rgb{0.1f, 0.2f, 0.3f};
        rgb.setRed(0.4f);
        rgb.setGreen(0.5f);
        rgb.setBlue(0.6f);
        REQUIRE(rgb.getRed() == 0.4f);
        REQUIRE(rgb.getGreen() == 0.5f);
        REQUIRE(rgb.getBlue() == 0.6f);
    }

    SECTION("gets color") {
        RGB rgb{0.1f, 0.2f, 0.3f};
        REQUIRE(rgb.getColor() == (
            (static_cast<unsigned int>(std::round(0.1f * 255.0f)) << 16)
            | (static_cast<unsigned int>(std::round(0.2f * 255.0f)) << 8)
            | static_cast<unsigned int>(std::round(0.3f * 255.0f))
        ));
    }

    SECTION("sets color") {
        RGB rgb{};
        rgb.setColor(
            (static_cast<unsigned int>(std::round(0.1f * 255.0f)) << 16)
            | (static_cast<unsigned int>(std::round(0.2f * 255.0f)) << 8)
            | static_cast<unsigned int>(std::round(0.3f * 255.0f))
        );
        REQUIRE(rgb.getRed() == Approx(0.1f).epsilon(0.5f / 255.0f));
        REQUIRE(rgb.getGreen() == Approx(0.2f).epsilon(0.5f / 255.0f));
        REQUIRE(rgb.getBlue() == Approx(0.3f).epsilon(0.5f / 255.0f));
    }

    SECTION("create from another RGB") {
        RGB rgb1{0.1f, 0.2f, 0.3f};
        RGB rgb2{rgb1};

        REQUIRE(rgb2.getRed() == 0.1f);
        REQUIRE(rgb2.getGreen() == 0.2f);
        REQUIRE(rgb2.getBlue() == 0.3f);
    }

    SECTION("create from another RGB (verify)") {
        RGB rgb1{0.1f, 0.2f, 0.3f};
        RGB rgb2{rgb1};

        rgb2.setRed(0.4f);
        rgb2.setGreen(0.5f);
        rgb2.setBlue(0.6f);

        REQUIRE(rgb1.getRed() == 0.1f);
        REQUIRE(rgb1.getGreen() == 0.2f);
        REQUIRE(rgb1.getBlue() == 0.3f);

        REQUIRE(rgb2.getRed() == 0.4f);
        REQUIRE(rgb2.getGreen() == 0.5f);
        REQUIRE(rgb2.getBlue() == 0.6f);
    }

    SECTION("interpolate") {
        //RGB rgb1{};
        //RGB rgb2{10,20,30};
        //RGB rgb3 = rgb1.interpolate(rgb2);
        //REQUIRE(rgb3.getRed() == 5);
        //REQUIRE(rgb3.getGreen() == 10);
        //REQUIRE(rgb3.getBlue() == 15);
    }
}
