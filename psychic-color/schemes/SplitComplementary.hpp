#pragma once

#include "ColorWheelScheme.hpp"
#include "../spaces/HSB.hpp"
#include "../PsychicColor.hpp"

namespace psychic_color {

    constexpr std::size_t numColors = 3;

    template<class T>
    class SplitComplementary : public ColorWheelScheme<T, numColors> {
    public:
        explicit SplitComplementary(const T &primaryColor);
    protected:
        void generate() override;
    };

    template<class T>
    SplitComplementary<T>::SplitComplementary(const T &primaryColor):
        ColorWheelScheme<T, numColors>(primaryColor) {
        generate();
    }

    template<class T>
    void SplitComplementary<T>::generate() {
        HSB primary{this->_primaryColor};

        HSB c1{PsychicColor::rybRotate(primary, 150.0f)};
        c1.brighten(0.1f);

        HSB c2{PsychicColor::rybRotate(primary, 210.0f)};
        c2.brighten(0.1f);

        _colors[0] = std::move(primary);
        _colors[1] = std::move(c1);
        _colors[2] = std::move(c2);
    }

}

