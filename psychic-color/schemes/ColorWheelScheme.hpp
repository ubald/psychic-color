#pragma once

#include <array>
#include <lib/psychic-color/psychic-color/PsychicColor.hpp>
#include "ColorScheme.hpp"

namespace psychic_color {

    template<class T, std::size_t N>
    class ColorWheelScheme : public ColorScheme<T, N> {
    public:
        explicit ColorWheelScheme(const T &primaryColor, bool ryb = false);
    protected:
        std::function<T(HSB, float)> rotate{};

        inline static constexpr float wrap(float x, float min, float threshold, float plus);
    };

    template<class T, std::size_t N>
    ColorWheelScheme<T, N>::ColorWheelScheme(const T &primaryColor, bool ryb):
        ColorScheme<T, N>(primaryColor) {
        if (ryb) {
            rotate = PsychicColor::rybRotate<T>;
        } else {
            rotate = [](auto color, float angle) {
                color.shiftHueAngle(angle);
                return color;
            };
        }
    }

    template<class T, std::size_t N>
    inline constexpr float ColorWheelScheme<T, N>::wrap(
        const float x, const float min, const float threshold, const float plus
    ) {
        return x - min < threshold ? x + plus : x - min;
    }

}

