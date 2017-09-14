#pragma once

#include "Color.hpp"

namespace psychic_color {

    class RGB : public Color {
    public:
        RGB(const float red = 0.0f, const float green = 0.0f, const float blue = 0.0f);
        RGB(const RGB &rgb);
        RGB(const unsigned int color);

        virtual operator RGB() const override;

        float getRed() const;
        void setRed(const float red);
        float getGreen() const;
        void setGreen(const float green);
        float getBlue() const;
        void setBlue(const float blue);

        virtual unsigned int getColor() const override;
        virtual void setColor(const unsigned int color) override;
        //virtual RGB interpolate( Color &target, const float ratio = 0.5f) const override;

    protected:
        float _red{0.0f};
        float _green{0.0f};
        float _blue{0.0f};
    };
}
