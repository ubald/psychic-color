#pragma once

#include <type_traits>
#include "../spaces/Color.hpp"

namespace psychic_color {

    template<class T, std::size_t N>
    class ColorScheme {
        static_assert(std::is_base_of<Color, T>::value, "T must extend Color");
    public:
        explicit ColorScheme(const T &primaryColor);
        T getColor(unsigned int index) const;
        virtual void generate() = 0;
    protected:
        const T          &_primaryColor;
        std::array<T, N> _colors;
    };

    template<class T, std::size_t N>
    ColorScheme<T, N>::ColorScheme(const T &primaryColor):
        _primaryColor(primaryColor) {}

    template<class T, std::size_t N>
    T ColorScheme<T, N>::getColor(const unsigned int index) const {
        return _colors[index];
    }
}
