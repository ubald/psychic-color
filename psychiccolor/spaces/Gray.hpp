#pragma once

#include "Color.hpp"

namespace psychic_color {
    class RGB;

    class Gray : public Color {
    public:
        inline static float rgbToGray(float red, float green, float blue);
        Gray(float gray = 0.0f);
        Gray(const Gray &gray);
        Gray(const RGB &rgb);
        Gray(const unsigned int color);

        operator RGB() const override;

        float getGray() const;
        void setGray(const float gray);

        virtual unsigned int getColor() const override;
        virtual void setColor(const unsigned int color) override;
        //virtual Gray interpolate( Color &target, const float ratio = 0.5f) const override;

    private:
        float _gray{0.0f};
    };
}
