#pragma once

#include "Color.hpp"

namespace psychic_color {
    class RGB;

    class HSB: public Color {
    public:
        HSB(const float hue = 0.0f, const float saturation = 0.0f, const float brightness = 0.0f);
        HSB(const HSB &hsb);
        HSB(const RGB &rgb);
        HSB(const unsigned int color);

        operator RGB() const override;

        float getHue() const;
        void setHue(const float hue);
        void shiftHue(const float hue);

        float getSaturation() const;
        void setSaturation(const float saturation);
        void saturate(const float saturation);
        void desaturate(const float saturation);


        float getBrightness() const;
        void setBrightness(const float brightness);
        void brighten(const float brightness);
        void darken(const float brightness);

        virtual unsigned int getColor() const override;
        virtual void setColor(const unsigned int color) override;
        //virtual RGB interpolate( Color &target, const float ratio = 0.5f) const override;

    private:
        float _hue{0.0f};
        float _saturation{0.0f};
        float _brightness{0.0f};
    };
    
}
