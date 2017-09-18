#pragma once

#include <array>
#include "psychic-color/PsychicColor.hpp"
#include "ColorScheme.hpp"

namespace psychic_color {

    template<class T, std::size_t N>
    class ColorWheelScheme : public ColorScheme<T, N> {
    public:
        explicit ColorWheelScheme(const T &primaryColor, bool ryb = false);
    protected:
        HSB rotate(HSB color, float angle);
        bool _ryb{false};
        inline static constexpr float wrap(float x, float min, float threshold, float plus);
    };

    template<class T, std::size_t N>
    ColorWheelScheme<T, N>::ColorWheelScheme(const T &primaryColor, bool ryb):
        ColorScheme<T, N>(primaryColor), _ryb(ryb) {}

    template<class T, std::size_t N>
    HSB ColorWheelScheme<T, N>::rotate(HSB color, float angle) {
        if (_ryb) {
            return PsychicColor::rybRotate(color, angle);
        } else {
            color.shiftHueAngle(angle);
            return color;
        }
    }

    template<class T, std::size_t N>
    inline constexpr float ColorWheelScheme<T, N>::wrap(
        const float x, const float min, const float threshold, const float plus
    ) {
        return x - min < threshold ? x + plus : x - min;
    }

}

