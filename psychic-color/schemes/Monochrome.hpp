#pragma once

#include "ColorWheelScheme.hpp"
#include "../spaces/HSB.hpp"
#include "../PsychicColor.hpp"

namespace psychic_color {

    constexpr std::size_t numColors = 5;

    template<class T>
    class Monochrome : public ColorWheelScheme<T, numColors> {
    public:
        explicit Monochrome(const T &primaryColor);
    protected:
        void generate() override;
    };

    template<class T>
    Monochrome<T>::Monochrome(const T &primaryColor):
        ColorWheelScheme<T, numColors>(primaryColor) {
        generate();
    }

    template<class T>
    void Monochrome<T>::generate() {
        HSB primary{this->_primaryColor};

        HSB c1{primary};
        c1.setBrightness(wrap(primary.getBrightness(), 0.50f, 0.20f, 0.30f));
        c1.setSaturation(wrap(primary.getSaturation(), 0.30f, 0.10f, 0.20f));

        HSB c2{primary};
        c2.setBrightness(wrap(primary.getBrightness(), 0.20f, 0.20f, 0.60f));

        HSB c3{primary};
        c3.setBrightness(std::max(0.2f, primary.getBrightness() + (1.0f - primary.getBrightness()) * 0.2f));
        c3.setSaturation(wrap(primary.getSaturation(), 0.30f, 0.10f, 0.30f));

        HSB c4{primary};
        c4.setBrightness(wrap(primary.getBrightness(), 0.50f, 0.20f, 0.30f));

        _colors[0] = std::move(primary);
        _colors[1] = std::move(c1);
        _colors[2] = std::move(c2);
        _colors[3] = std::move(c3);
        _colors[4] = std::move(c4);
    }

}

