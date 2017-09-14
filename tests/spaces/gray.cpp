#include <cmath>
#include "catch.hpp"
#include <psychic-color/spaces/Gray.hpp>
#include <iostream>

using namespace psychic_color;

TEST_CASE("Gray") {

    SECTION("initializes") {
        Gray gray{0.1f};
        REQUIRE(gray.getGray() == 0.1f);
    }

    SECTION("sets") {
        Gray gray{0.1f};
        gray.setGray(0.2f);
        REQUIRE(gray.getGray() == 0.2f);
    }

    SECTION("gets color") {
        Gray gray{0.1f};
        REQUIRE(gray.getColor() == ((static_cast<unsigned int>(std::round(0.1f * 255.0f)) << 16)
                                    | (static_cast<unsigned int>(std::round(0.1f * 255.0f)) << 8)
                                    | static_cast<unsigned int>(std::round(0.1f * 255.0f))));
    }

    SECTION("sets color") {
        Gray gray{};
        gray.setColor(((static_cast<unsigned int>(std::round(0.1f * 255.0f)) << 16)
                       | (static_cast<unsigned int>(std::round(0.2f * 255.0f)) << 8)
                       | static_cast<unsigned int>(std::round(0.3f * 255.0f))));
        REQUIRE(gray.getGray() == Approx(0.3f * 0.1f + 0.59f * 0.2f + 0.11f * 0.3f).epsilon(0.5f / 255.0f));
    }

    SECTION("create from another Gray") {
        Gray gray1{0.1f};
        Gray gray2{gray1};

        REQUIRE(gray2.getGray() == 0.1f);
    }

    SECTION("create from another Gray (verify)") {
        Gray gray1{0.1f};
        Gray gray2{gray1};

        gray2.setGray(0.2f);

        REQUIRE(gray1.getGray() == 0.1f);

        REQUIRE(gray2.getGray() == 0.2f);
    }

    SECTION("interpolate") {
        //Gray gray0.1f{};
        //Gray gray0.2f{0.1f0.0f};
        //Gray gray0.3f = gray0.1f.interpolate(gray0.2f);
        //REQUIRE(rgb0.3f.getGray() == 0.5f);
    }
}
