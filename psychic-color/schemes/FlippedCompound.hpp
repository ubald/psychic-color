#pragma once

#include "ColorWheelScheme.hpp"
#include "../spaces/HSB.hpp"
#include "../PsychicColor.hpp"

namespace psychic_color {

    constexpr std::size_t numColors = 6;

    template<class T>
    class FlippedCompound : public ColorWheelScheme<T, numColors> {
    public:
        explicit FlippedCompound(const T &primaryColor);
    protected:
        void generate() override;
    };

    template<class T>
    FlippedCompound<T>::FlippedCompound(const T &primaryColor):
        ColorWheelScheme<T, numColors>(primaryColor) {
        generate();
    }

    template<class T>
    void FlippedCompound<T>::generate() {
        HSB primary{this->_primaryColor};

        HSB c1{PsychicColor::rybRotate(primary, -30.0f)};
        c1.setBrightness(wrap(primary.getBrightness(), 0.25f, 0.60f, 0.25f));

        HSB c2{PsychicColor::rybRotate(primary, -30.0f)};
        c2.setBrightness(wrap(primary.getBrightness(), 0.40f, 0.10f, 0.40f));
        c2.setSaturation(wrap(primary.getSaturation(), 0.40f, 0.20f, 0.40f));

        HSB c3{PsychicColor::rybRotate(primary, -160.0f)};
        c3.setBrightness(wrap(primary.getBrightness(), 0.25f, 0.10f, 0.25f));

        HSB c4{PsychicColor::rybRotate(primary, -150.0f)};
        c4.setBrightness(wrap(primary.getBrightness(), 0.30f, 0.60f, 0.30f));
        c4.setSaturation(wrap(primary.getSaturation(), 0.10f, 0.80f, 0.10f));

        HSB c5{PsychicColor::rybRotate(primary, -150.0f)};
        c5.setBrightness(wrap(primary.getBrightness(), 0.40f, 0.20f, 0.40f));
        c5.setSaturation(wrap(primary.getSaturation(), 0.10f, 0.80f, 0.10f));

        _colors[0] = std::move(static_cast<T>(primary));
        _colors[1] = std::move(static_cast<T>(c1));
        _colors[2] = std::move(static_cast<T>(c2));
        _colors[3] = std::move(static_cast<T>(c3));
        _colors[4] = std::move(static_cast<T>(c4));
        _colors[5] = std::move(static_cast<T>(c5));
    }

}

