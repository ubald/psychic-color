#pragma once

#include <cmath>

namespace psychic_color {
    class RGB;

    class Color {
    public:
        Color() = default;

        virtual explicit operator RGB() const = 0;

        virtual unsigned int getColor() const = 0;
        virtual void setColor(unsigned int color) = 0;
        //virtual Color interpolate( Color &target, const float ratio = 0.5f) const = 0;
        bool operator==(const Color &other) const {
            return getColor() == other.getColor();
        }
    };
}
