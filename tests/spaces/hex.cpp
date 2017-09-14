#include <cmath>
#include "catch.hpp"
#include <iostream>
#include <psychic-color/spaces/Hex.hpp>

using namespace psychic_color;

TEST_CASE("Hex") {
    unsigned int val = (1 << 24) | (2 << 16) | (3 << 8) | 4;

    SECTION("initializes") {
        Hex hex{val};
        REQUIRE(hex.getAlpha() == 1);
        REQUIRE(hex.getRed() == 2);
        REQUIRE(hex.getGreen() == 3);
        REQUIRE(hex.getBlue() == 4);
    }

    SECTION("sets") {
        Hex hex{val};
        hex.setAlpha(5);
        hex.setRed(6);
        hex.setGreen(7);
        hex.setBlue(8);
        REQUIRE(hex.getAlpha() == 5);
        REQUIRE(hex.getRed() == 6);
        REQUIRE(hex.getGreen() == 7);
        REQUIRE(hex.getBlue() == 8);
    }

    SECTION("gets color") {
        Hex hex{val};
        REQUIRE(hex.getColor() == val);
    }

    SECTION("sets color") {
        Hex hex{};
        hex.setColor(val);
        REQUIRE(hex.getColor() == val);
        REQUIRE(hex.getAlpha() == 1);
        REQUIRE(hex.getRed() == 2);
        REQUIRE(hex.getGreen() == 3);
        REQUIRE(hex.getBlue() == 4);
    }

    SECTION("create from another Hex") {
        Hex hex1{val};
        Hex hex2{hex1};

        REQUIRE(hex2.getAlpha() == 1);
        REQUIRE(hex2.getRed() == 2);
        REQUIRE(hex2.getGreen() == 3);
        REQUIRE(hex2.getBlue() == 4);
    }

    SECTION("create from another Hex (verify)") {
        Hex hex1{val};
        Hex hex2{hex1};

        hex2.setAlpha(5);
        hex2.setRed(6);
        hex2.setGreen(7);
        hex2.setBlue(8);

        REQUIRE(hex1.getAlpha() == 1);
        REQUIRE(hex1.getRed() == 2);
        REQUIRE(hex1.getGreen() == 3);
        REQUIRE(hex1.getBlue() == 4);

        REQUIRE(hex2.getAlpha() == 5);
        REQUIRE(hex2.getRed() == 6);
        REQUIRE(hex2.getGreen() == 7);
        REQUIRE(hex2.getBlue() == 8);
    }

    SECTION("interpolate") {
        //Hex hex0.1f{};
        //Hex hex0.2f{0.1f0.0f,0.2f0.0f,0.3f0.0f, 0.4f0.0f};
        //Hex hex0.3f = hex0.1f.interpolate(hex0.2f);
        //REQUIRE(hex0.3f.getAlpha() == 0.5f);
        //REQUIRE(hex0.3f.getRed() == 0.1f0.0f);
        //REQUIRE(hex0.3f.getGreen() == 0.1f0.5f);
        //REQUIRE(hex0.3f.getBlue() == 0.2f0.0f);
    }
}
