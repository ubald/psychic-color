#include <cmath>
#include "catch.hpp"
#include <psychic-color/spaces/RGB.hpp>
#include <psychic-color/spaces/HSL.hpp>
#include <iostream>

using namespace psychic_color;

TEST_CASE("HSL") {

    SECTION("initializes") {
        HSL hsl{0.1f, 0.2f, 0.3f};
        REQUIRE(hsl.getHue() == 0.1f);
        REQUIRE(hsl.getSaturation() == 0.2f);
        REQUIRE(hsl.getLightness() == 0.3f);
    }

    SECTION("sets") {
        HSL hsl{0.1f, 0.2f, 0.3f};
        hsl.setHue(0.4f);
        hsl.setSaturation(0.5f);
        hsl.setLightness(0.6f);
        REQUIRE(hsl.getHue() == 0.4f);
        REQUIRE(hsl.getSaturation() == 0.5f);
        REQUIRE(hsl.getLightness() == 0.6f);
    }

    SECTION("create from another HSL") {
        HSL hsl1{0.1f, 0.2f, 0.3f};
        HSL hsl2{hsl1};

        REQUIRE(hsl2.getHue() == 0.1f);
        REQUIRE(hsl2.getSaturation() == 0.2f);
        REQUIRE(hsl2.getLightness() == 0.3f);
    }

    SECTION("create from another HSL (verify)") {
        HSL hsl1{0.1f, 0.2f, 0.3f};
        HSL hsl2{hsl1};

        hsl2.setHue(0.4f);
        hsl2.setSaturation(0.5f);
        hsl2.setLightness(0.6f);

        REQUIRE(hsl1.getHue() == 0.1f);
        REQUIRE(hsl1.getSaturation() == 0.2f);
        REQUIRE(hsl1.getLightness() == 0.3f);

        REQUIRE(hsl2.getHue() == 0.4f);
        REQUIRE(hsl2.getSaturation() == 0.5f);
        REQUIRE(hsl2.getLightness() == 0.6f);
    }

    SECTION("interpolate") {
        //HSL hsl1{};
        //HSL hsl2{10,20,30};
        //HSL hsl3 = hsl1.interpolate(hsl2);
        //REQUIRE(hsl3.getHue() == 5);
        //REQUIRE(hsl3.getSaturation() == 10);
        //REQUIRE(hsl3.getBrightness() == 15);
    }

    SECTION("conversions") {

        SECTION("from RGB") {

            SECTION("red") {
                RGB rgb{1.0f, 0.0f, 0.0f};
                HSL hsl{rgb};
                REQUIRE(hsl.getHue() == 0.0f);
                REQUIRE(hsl.getHueAngle() == 0.0f);
                REQUIRE(hsl.getSaturation() == 1.0f);
                REQUIRE(hsl.getLightness() == 0.5f);
            }

            SECTION("green") {
                RGB rgb{0.0f, 1.0f, 0.0f};
                HSL hsl{rgb};
                REQUIRE(hsl.getHue() == 1.0f / 3.0f);
                REQUIRE(hsl.getHueAngle() == 120.0f);
                REQUIRE(hsl.getSaturation() == 1.0f);
                REQUIRE(hsl.getLightness() == 0.5f);
            }

            SECTION("blue") {
                RGB rgb{0.0f, 0.0f, 1.0f};
                HSL hsl{rgb};
                REQUIRE(hsl.getHue() == 2.0f / 3.0f);
                REQUIRE(hsl.getHueAngle() == 240.0f);
                REQUIRE(hsl.getSaturation() == 1.0f);
                REQUIRE(hsl.getLightness() == 0.5f);
            }
        }

        SECTION("to RGB") {

            SECTION("red") {
                HSL hsl{0.0f, 1.0f, 0.5f};
                RGB rgb{static_cast<RGB>(hsl)};
                REQUIRE(rgb.getRed() == 1.0f);
                REQUIRE(rgb.getGreen() == 0.0f);
                REQUIRE(rgb.getBlue() == Approx(0.0f)); // I don't know why this one needs approximation
            }

            SECTION("green") {
                HSL hsl{1.0f / 3.0f, 1.0f, 0.5f};
                RGB rgb{static_cast<RGB>(hsl)};
                REQUIRE(rgb.getRed() == 0.0f);
                REQUIRE(rgb.getGreen() == 1.0f);
                REQUIRE(rgb.getBlue() == 0.0f);
            }

            SECTION("blue") {
                HSL hsl{2.0f / 3.0f, 1.0f, 0.5f};
                RGB rgb{static_cast<RGB>(hsl)};
                REQUIRE(rgb.getRed() == 0.0f);
                REQUIRE(rgb.getGreen() == 0.0f);
                REQUIRE(rgb.getBlue() == 1.0f);
            }


        }
    }
}
