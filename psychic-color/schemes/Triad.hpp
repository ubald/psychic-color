#pragma once

#include "ColorWheelScheme.hpp"
#include "../spaces/HSB.hpp"
#include "../PsychicColor.hpp"

namespace psychic_color {

    constexpr std::size_t TriadNumColors = 3;

    template<class T>
    class Triad : public ColorWheelScheme<T, TriadNumColors> {
    public:
        explicit Triad(const T &primaryColor, bool ryb = false);
        void generate() override;
    };

    template<class T>
    Triad<T>::Triad(const T &primaryColor, bool ryb):
        ColorWheelScheme<T, TriadNumColors>(primaryColor, ryb) {
        generate();
    }

    template<class T>
    void Triad<T>::generate() {
        HSB primary{this->_primaryColor};
        HSB c1{this->rotate(primary, 120.0f)};
        HSB c2{this->rotate(primary, 240.0f)};

        this->_colors[0] = std::move(static_cast<T>(primary));
        this->_colors[1] = std::move(static_cast<T>(c1));
        this->_colors[2] = std::move(static_cast<T>(c2));
    }

}

