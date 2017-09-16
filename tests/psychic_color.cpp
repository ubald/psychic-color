#include <cmath>
#include <iostream>
#include "catch.hpp"
#include <psychic-color/PsychicColor.hpp>

using namespace psychic_color;

TEST_CASE("PsychicColor") {

    SECTION("ryb rotate") {

        float eps = 0.5f / 255.0f;

        SECTION("RGB") {

            SECTION("red") {
                SECTION("0") {
                    RGB rgb1{1.0f, 0.0f, 0.0f};
                    RGB rgb2(PsychicColor::rybRotate(rgb1, 0.0f));
                    REQUIRE(rgb1 == rgb2);
                }

                SECTION("180") {
                    RGB rgb1{1.0f, 0.0f, 0.0f};
                    RGB rgb2(PsychicColor::rybRotate(rgb1, 180.0f));
                    REQUIRE(rgb2.getRed() == 0.0f);
                    REQUIRE(rgb2.getGreen() == 1.0f);
                    REQUIRE(rgb2.getBlue() == Approx(72.f / 255.f).epsilon(eps));
                }
            }

            SECTION("yellow") {
                SECTION("0") {
                    RGB rgb1{1.0f, 1.0f, 0.0f};
                    RGB rgb2(PsychicColor::rybRotate(rgb1, 0.0f));
                    REQUIRE(rgb1 == rgb2);
                }

                SECTION("180") {
                    RGB rgb1{1.0f, 1.0f, 0.0f};
                    RGB rgb2(PsychicColor::rybRotate(rgb1, 180.0f));
                    REQUIRE(rgb2.getRed() == Approx(0.490196078431373f).epsilon(eps));
                    REQUIRE(rgb2.getGreen() == 0.0f);
                    REQUIRE(rgb2.getBlue() == 1.0f);
                }
            }

            SECTION("green") {
                SECTION("0") {
                    RGB rgb1{0.0f, 1.0f, 0.0f};
                    RGB rgb2(PsychicColor::rybRotate(rgb1, 0.0f));
                    REQUIRE(rgb1 == rgb2);
                }

                SECTION("180") {
                    RGB rgb1{0.0f, 1.0f, 0.0f};
                    RGB rgb2(PsychicColor::rybRotate(rgb1, 180.0f));
                    REQUIRE(rgb2 == RGB(1.0f, 0.0f, 0.5f));
                }
            }

            SECTION("cyan") {
                SECTION("0") {
                    RGB rgb1{0.0f, 1.0f, 1.0f};
                    RGB rgb2(PsychicColor::rybRotate(rgb1, 0.0f));
                    REQUIRE(rgb1 == rgb2);
                }

                SECTION("180") {
                    RGB rgb1{0.0f, 1.0f, 1.0f};
                    RGB rgb2(PsychicColor::rybRotate(rgb1, 180.0f));
                    REQUIRE(rgb2.getRed() == 1.0f);
                    REQUIRE(rgb2.getGreen() == Approx(94.f / 255.f).epsilon(eps));
                    REQUIRE(rgb2.getBlue() == 0.0f);
                }
            }

            SECTION("blue") {
                SECTION("0") {
                    RGB rgb1{0.0f, 0.0f, 1.0f};
                    RGB rgb2(PsychicColor::rybRotate(rgb1, 0.0f));
                    REQUIRE(rgb1 == rgb2);
                }

                SECTION("180") {
                    RGB rgb1{0.0f, 0.0f, 1.0f};
                    RGB rgb2(PsychicColor::rybRotate(rgb1, 180.0f));
                    REQUIRE(rgb2.getRed() == 1.0f);
                    REQUIRE(rgb2.getGreen() == Approx(0.819607843137255f).epsilon(eps));
                    REQUIRE(rgb2.getBlue() == 0.0f);
                }
            }

            SECTION("magenta") {
                SECTION("0") {
                    RGB rgb1{1.0f, 0.0f, 1.0f};
                    RGB rgb2(PsychicColor::rybRotate(rgb1, 0.0f));
                    REQUIRE(rgb1 == rgb2);
                }

                SECTION("180") {
                    RGB rgb1{1.0f, 0.0f, 1.0f};
                    RGB rgb2(PsychicColor::rybRotate(rgb1, 180.0f));
                    REQUIRE(rgb2.getRed() == Approx(89.f / 255.f).epsilon(eps));
                    REQUIRE(rgb2.getGreen() == 1.0f);
                    REQUIRE(rgb2.getBlue() == 0.0f);
                }
            }

        }

    }

}
