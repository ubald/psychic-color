#pragma once

#include <iostream>
#include "RGB.hpp"

namespace psychic_color {

    class ARGB : public RGB {
    public:
        explicit ARGB(float alpha = 0.0f, float red = 0.0f, float green = 0.0f, float blue = 0.0f);
        ARGB(const ARGB &argb);
        explicit ARGB(const RGB &rgb);
        explicit ARGB(unsigned int color);

        operator RGB() const override;

        float getAlpha() const;
        void setAlpha(float alpha);

        unsigned int getColor() const override;
        void setColor(unsigned int color) override;
        //virtual RGB interpolate( Color &target, const float ratio = 0.5f) const override;

        friend std::ostream& operator << ( std::ostream& os, const ARGB& argb ) {
            os << "ARGB(alpha: " << argb.getAlpha() << ", red: " << argb.getRed() << ", green: " << argb.getGreen() << ", blue: " << argb.getBlue() << ")";
            return os;
        }

    protected:
        float _alpha{0.0f};
    };
}
