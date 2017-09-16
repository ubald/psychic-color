#pragma once

#include <iostream>
#include "RGB.hpp"

namespace psychic_color {

    class ARGB : public RGB {
    public:
        ARGB(const float alpha = 0.0f, const float red = 0.0f, const float green = 0.0f, const float blue = 0.0f);
        ARGB(const ARGB &argb);
        ARGB(const RGB &rgb);
        ARGB(const unsigned int color);

        operator RGB() const override;

        float getAlpha() const;
        void setAlpha(const float alpha);

        virtual unsigned int getColor() const override;
        virtual void setColor(const unsigned int color) override;
        //virtual RGB interpolate( Color &target, const float ratio = 0.5f) const override;

        friend std::ostream& operator << ( std::ostream& os, const ARGB& argb ) {
            os << "ARGB(alpha: " << argb.getAlpha() << ", red: " << argb.getRed() << ", green: " << argb.getGreen() << ", blue: " << argb.getBlue() << ")";
            return os;
        }

    protected:
        float _alpha{0.0f};
    };
}
