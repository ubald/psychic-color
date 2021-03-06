#pragma once

#include <iostream>
#include "Color.hpp"

namespace psychic_color {

    class RGB : public Color {
    public:
        explicit RGB(float red = 0.0f, float green = 0.0f, float blue = 0.0f);
        RGB(const RGB &rgb);
        RGB(unsigned int color);

        explicit operator RGB() const override;

        float getRed() const;
        void setRed(float red);
        float getGreen() const;
        void setGreen(float green);
        float getBlue() const;
        void setBlue(float blue);

        unsigned int getColor() const override;
        void setColor(unsigned int color) override;
        //virtual RGB interpolate( Color &target, const float ratio = 0.5f) const override;

        friend std::ostream &operator<<(std::ostream &os, const RGB &rgb) {
            os << "RGB(red: " << rgb.getRed() << ", green: " << rgb.getGreen() << ", blue: " << rgb.getBlue() << ")";
            return os;
        }

    protected:
        float _red{0.0f};
        float _green{0.0f};
        float _blue{0.0f};
    };
}
