#pragma once

#include <iostream>
#include "Color.hpp"

namespace psychic_color {
    class RGB;

    class Hex : public Color {
    public:
        explicit Hex(unsigned int color = 0);
        Hex(const Hex &hex);

        explicit operator RGB() const override;

        unsigned int getAlpha() const;
        void setAlpha(unsigned int alpha);
        unsigned int  getRed() const;
        void setRed(unsigned int  red);
        unsigned int  getGreen() const;
        void setGreen(unsigned int green);
        unsigned int  getBlue() const;
        void setBlue(unsigned int blue);

        unsigned int getColor() const override;
        void setColor(unsigned int color) override;
        //virtual RGB interpolate( Color &target, const float ratio = 0.5f) const override;

        friend std::ostream& operator << ( std::ostream& os, const Hex& hex ) {
            os << "Hexa(alpha: " << hex.getAlpha() << ", red: " << hex.getRed() << ", green: " << hex.getGreen() << ", blue: " << hex.getBlue() << ")";
            return os;
        }

    protected:
        unsigned int _color{0};
    };
}
