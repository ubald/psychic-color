#include <cmath>
#include "catch.hpp"
#include <psychic-color/spaces/RGB.hpp>
#include <psychic-color/spaces/HSB.hpp>
#include <iostream>

using namespace psychic_color;

TEST_CASE("HSB") {

    SECTION("initializes") {
        HSB hsb{0.1f, 0.2f, 0.3f};
        REQUIRE(hsb.getHue() == 0.1f);
        REQUIRE(hsb.getSaturation() == 0.2f);
        REQUIRE(hsb.getBrightness() == 0.3f);
    }

    SECTION("sets") {
        HSB hsb{0.1f, 0.2f, 0.3f};
        hsb.setHue(0.4f);
        hsb.setSaturation(0.5f);
        hsb.setBrightness(0.6f);
        REQUIRE(hsb.getHue() == 0.4f);
        REQUIRE(hsb.getSaturation() == 0.5f);
        REQUIRE(hsb.getBrightness() == 0.6f);
    }

    SECTION("create from another HSB") {
        HSB hsb1{0.1f, 0.2f, 0.3f};
        HSB hsb2{hsb1};

        REQUIRE(hsb2.getHue() == 0.1f);
        REQUIRE(hsb2.getSaturation() == 0.2f);
        REQUIRE(hsb2.getBrightness() == 0.3f);
    }

    SECTION("create from another HSB (verify)") {
        HSB hsb1{0.1f, 0.2f, 0.3f};
        HSB hsb2{hsb1};

        hsb2.setHue(0.4f);
        hsb2.setSaturation(0.5f);
        hsb2.setBrightness(0.6f);

        REQUIRE(hsb1.getHue() == 0.1f);
        REQUIRE(hsb1.getSaturation() == 0.2f);
        REQUIRE(hsb1.getBrightness() == 0.3f);

        REQUIRE(hsb2.getHue() == 0.4f);
        REQUIRE(hsb2.getSaturation() == 0.5f);
        REQUIRE(hsb2.getBrightness() == 0.6f);
    }

    SECTION("interpolate") {
        //HSB hsb1{};
        //HSB hsb2{10,20,30};
        //HSB hsb3 = hsb1.interpolate(hsb2);
        //REQUIRE(hsb3.getHue() == 5);
        //REQUIRE(hsb3.getSaturation() == 10);
        //REQUIRE(hsb3.getBrightness() == 15);
    }

    SECTION("conversions") {

        SECTION("from RGB") {

            SECTION("red") {
                RGB rgb{1.0f, 0.0f, 0.0f};
                HSB hsb{rgb};
                REQUIRE(hsb.getHue() == 0.0f);
                REQUIRE(hsb.getHueAngle() == 0.0f);
                REQUIRE(hsb.getSaturation() == 1.0f);
                REQUIRE(hsb.getBrightness() == 1.0f);
            }

            SECTION("green") {
                RGB rgb{0.0f, 1.0f, 0.0f};
                HSB hsb{rgb};
                REQUIRE(hsb.getHue() == 1.0f / 3.0f);
                REQUIRE(hsb.getHueAngle() == 120.0f);
                REQUIRE(hsb.getSaturation() == 1.0f);
                REQUIRE(hsb.getBrightness() == 1.0f);
            }

            SECTION("blue") {
                RGB rgb{0.0f, 0.0f, 1.0f};
                HSB hsb{rgb};
                REQUIRE(hsb.getHue() == 2.0f / 3.0f);
                REQUIRE(hsb.getHueAngle() == 240.0f);
                REQUIRE(hsb.getSaturation() == 1.0f);
                REQUIRE(hsb.getBrightness() == 1.0f);
            }
        }

        SECTION("to RGB") {

            SECTION("red") {
                HSB hsb{1.0f, 1.0f, 1.0f};
                RGB rgb{hsb};
                REQUIRE(rgb.getRed() == 1.0f);
                REQUIRE(rgb.getGreen() == 0.0f);
                REQUIRE(rgb.getBlue() == 0.0f);
            }

            SECTION("green") {
                HSB hsb{1.0f / 3.0f, 1.0f, 1.0f};
                RGB rgb{hsb};
                REQUIRE(rgb.getRed() == 0.0f);
                REQUIRE(rgb.getGreen() == 1.0f);
                REQUIRE(rgb.getBlue() == 0.0f);
            }

            SECTION("blue") {
                HSB hsb{2.0f / 3.0f, 1.0f, 1.0f};
                RGB rgb{hsb};
                REQUIRE(rgb.getRed() == 0.0f);
                REQUIRE(rgb.getGreen() == 0.0f);
                REQUIRE(rgb.getBlue() == 1.0f);
            }


        }
    }
}
