#pragma once

#include <array>
#include "ColorScheme.hpp"

namespace psychic_color {

    template<class T, std::size_t N>
    class ColorWheelScheme : public ColorScheme<T> {
    public:
        explicit ColorWheelScheme(const T &primaryColor);

        //T &getPrimaryColor() const;
        //void setPrimaryColor(const T &primaryColor);
        T getColor(unsigned int index) const;
    protected:
        const T                &_primaryColor;
        std::array<T, N> _colors;
        virtual void generate() = 0;

        inline static constexpr float wrap(float x, float min, float threshold, float plus);
    };

    template<class T, std::size_t N>
    ColorWheelScheme<T, N>::ColorWheelScheme(const T &primaryColor):
        ColorScheme<T>(), _primaryColor{primaryColor} {}

    //template<class T, std::size_t N>
    //T &ColorWheelScheme<T, N>::getPrimaryColor() const {
    //    return _primaryColor;
    //}
    //
    //template<class T, std::size_t N>
    //void ColorWheelScheme<T, N>::setPrimaryColor(const T &primaryColor) {
    //    if (primaryColor != _primaryColor) {
    //        //_primaryColor = primaryColor;
    //        generate();
    //    }
    //}

    template<class T, std::size_t N>
    T ColorWheelScheme<T, N>::getColor(const unsigned int index) const {
        return _colors[index];
    }

    template<class T, std::size_t N>
    inline constexpr float ColorWheelScheme<T, N>::wrap(
        const float x, const float min, const float threshold, const float plus
    ) {
        return x - min < threshold ? x + plus : x - min;
    }

}

