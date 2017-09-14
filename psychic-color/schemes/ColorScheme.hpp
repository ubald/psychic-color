#pragma once

#include <type_traits>
#include "../spaces/Color.hpp"

namespace psychic_color {

    template<class T>
    class ColorScheme {
        static_assert(std::is_base_of<Color, T>::value, "T must extend Color");


    };

}
