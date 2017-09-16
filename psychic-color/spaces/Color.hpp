#pragma once

#include <cmath>

namespace psychic_color {
    class RGB;

    class Color {
    public:
        virtual operator RGB() const = 0;

        virtual unsigned int getColor() const = 0;
        virtual void setColor(const unsigned int color) = 0;
        //virtual Color interpolate( Color &target, const float ratio = 0.5f) const = 0;
        bool operator==(const Color &other) const {
            return getColor() == other.getColor();
        }
    };
}
