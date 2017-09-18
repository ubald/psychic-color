#pragma once

#include <cmath>

namespace psychic_color {
    class RGB;

    class Color {
    public:
        Color() = default;

        virtual explicit operator RGB() const = 0;

        explicit operator unsigned int() const {
            return getColor();
        }

        virtual unsigned int getColor() const = 0;
        virtual void setColor(unsigned int color) = 0;

        unsigned int getColorAlpha() const {
            return 0xFF000000 | (getColor() & 0xffffff);
        }

        //virtual Color interpolate( Color &target, const float ratio = 0.5f) const = 0;
        bool operator==(const Color &other) const {
            return getColor() == other.getColor();
        }
    };
}
