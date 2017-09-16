#pragma once

#include <iostream>
#include "Color.hpp"

namespace psychic_color {
    class RGB;

    class Gray : public Color {
    public:
        inline static float rgbToGray(float red, float green, float blue);
        explicit Gray(float gray = 0.0f);
        Gray(const Gray &gray);
        explicit Gray(const RGB &rgb);
        explicit Gray(unsigned int color);

        explicit operator RGB() const override;

        float getGray() const;
        void setGray(float gray);

        unsigned int getColor() const override;
        void setColor(unsigned int color) override;
        //virtual Gray interpolate( Color &target, const float ratio = 0.5f) const override;

        friend std::ostream& operator << ( std::ostream& os, const Gray& gray ) {
            os << "Gray(gray: " << gray.getGray() << ")";
            return os;
        }

    private:
        float _gray{0.0f};
    };
}
