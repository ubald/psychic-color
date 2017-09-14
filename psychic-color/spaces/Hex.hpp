#pragma once

#include "Color.hpp"

namespace psychic_color {

    class Hex : public Color {
    public:
        Hex(const unsigned int color = 0);
        Hex(const Hex &hex);

        operator RGB() const override;

        unsigned int getAlpha() const;
        void setAlpha(const unsigned int  alpha);
        unsigned int  getRed() const;
        void setRed(const unsigned int  red);
        unsigned int  getGreen() const;
        void setGreen(const unsigned int  green);
        unsigned int  getBlue() const;
        void setBlue(const unsigned int  blue);

        virtual unsigned int getColor() const override;
        virtual void setColor(const unsigned int color) override;
        //virtual RGB interpolate( Color &target, const float ratio = 0.5f) const override;

    protected:
        unsigned int _color{0};
    };
}
