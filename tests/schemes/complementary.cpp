#include <cmath>
#include <iostream>
#include "catch.hpp"
#include <psychic-color/schemes/Complementary.hpp>

using namespace psychic_color;

TEST_CASE("Complementary") {

    float eps = 0.5f / 255.0f;

    SECTION("RGB Red -> RGB") {
        RGB rgb{1.0f, 0.0f, 0.0f};
        Complementary<RGB> c{rgb};

        REQUIRE(c.getColor(0) == RGB(1.0f, 0.0f, 0.0f));

        REQUIRE(c.getColor(3).getRed() == 0.0f);
        REQUIRE(c.getColor(3).getGreen() == 1.0f);
        REQUIRE(c.getColor(3).getBlue() == Approx(72.f / 255.f).epsilon(eps));
    }

}
