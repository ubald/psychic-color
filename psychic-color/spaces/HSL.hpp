#pragma once

#include "Color.hpp"

namespace psychic_color {
    class RGB;

    class HSL: public Color {
    public:
        inline static float hue2rgb(const float p, const float q, const float t);

        HSL(const float hue = 0.0f, const float saturation = 0.0f, const float lightness = 0.0f);
        HSL(const HSL &hsl);
        HSL(const RGB &rgb);
        HSL(const unsigned int color);

        operator RGB() const override;

        float getHue() const;
        void setHue(const float hue);
        void shiftHue(const float hue);

        float getSaturation() const;
        void setSaturation(const float saturation);
        void saturate(const float saturation);
        void desaturate(const float saturation);

        float getLightness() const;
        void setLightness(const float lightness);
        void lighten(const float lightness);
        void darken(const float lightness);

        virtual unsigned int getColor() const override;
        virtual void setColor(const unsigned int color) override;
        //virtual RGB interpolate( Color &target, const float ratio = 0.5f) const override;

    private:
        float _hue{0.0f};
        float _saturation{0.0f};
        float _lightness{0.0f};
    };
    
}
