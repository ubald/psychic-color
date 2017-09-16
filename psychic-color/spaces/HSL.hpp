#pragma once

#include <iostream>
#include "Color.hpp"

namespace psychic_color {
    class RGB;

    class HSL : public Color {
    public:
        inline static float hue2rgb(float p, float q, float t);

        explicit HSL(float hue = 0.0f, float saturation = 0.0f, float lightness = 0.0f);
        HSL(const HSL &hsl);
        explicit HSL(const RGB &rgb);
        explicit HSL(unsigned int color);

        explicit operator RGB() const override;

        float getHue() const;
        void setHue(float hue);
        void shiftHue(float hue);

        float getHueAngle() const;
        void setHueAngle(float hue);
        void shiftHueAngle(float hue);

        float getSaturation() const;
        void setSaturation(float saturation);
        void saturate(float saturation);
        void desaturate(float saturation);

        float getLightness() const;
        void setLightness(float lightness);
        void lighten(float lightness);
        void darken(float lightness);

        unsigned int getColor() const override;
        void setColor(unsigned int color) override;
        //virtual RGB interpolate( Color &target, const float ratio = 0.5f) const override;

        friend std::ostream &operator<<(std::ostream &os, const HSL &hsl) {
            os
                << "HSL(hue: "
                << hsl.getHue()
                << ", saturation: "
                << hsl.getSaturation()
                << ", lightness: "
                << hsl.getLightness()
                << ")";
            return os;
        }

    private:
        float _hue{0.0f};
        float _saturation{0.0f};
        float _lightness{0.0f};
    };

}
