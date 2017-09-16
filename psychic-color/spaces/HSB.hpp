#pragma once

#include <iostream>
#include "Color.hpp"

namespace psychic_color {
    class RGB;

    class HSB : public Color {
    public:
        explicit HSB(float hue = 0.0f, float saturation = 0.0f, float brightness = 0.0f);
        HSB(const HSB &hsb);
        explicit HSB(const RGB &rgb);
        explicit HSB(unsigned int color);

        operator RGB() const override;

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


        float getBrightness() const;
        void setBrightness(float brightness);
        void brighten(float brightness);
        void darken(float brightness);

        unsigned int getColor() const override;
        void setColor(unsigned int color) override;
        //virtual RGB interpolate( Color &target, const float ratio = 0.5f) const override;

        friend std::ostream &operator<<(std::ostream &os, const HSB &hsb) {
            os
                << "HSB(hue: "
                << hsb.getHue()
                << ", saturation: "
                << hsb.getSaturation()
                << ", brightness: "
                << hsb.getBrightness()
                << ")";
            return os;
        }

    private:
        float _hue{0.0f};
        float _saturation{0.0f};
        float _brightness{0.0f};
    };

}
