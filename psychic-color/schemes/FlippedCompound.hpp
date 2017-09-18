#pragma once

#include "ColorWheelScheme.hpp"
#include "../spaces/HSB.hpp"
#include "../PsychicColor.hpp"

namespace psychic_color {

    constexpr std::size_t FlippedCompoundNumColors = 6;

    template<class T>
    class FlippedCompound : public ColorWheelScheme<T, FlippedCompoundNumColors> {
    public:
        explicit FlippedCompound(const T &primaryColor, bool ryb = false);
        void generate() override;
    protected:
    };

    template<class T>
    FlippedCompound<T>::FlippedCompound(const T &primaryColor, bool ryb ):
        ColorWheelScheme<T, FlippedCompoundNumColors>(primaryColor, ryb) {
        generate();
    }

    template<class T>
    void FlippedCompound<T>::generate() {
        HSB primary{this->_primaryColor};

        HSB c1{this->rotate(primary, -30.0f)};
        c1.setBrightness(this->wrap(primary.getBrightness(), 0.25f, 0.60f, 0.25f));

        HSB c2{this->rotate(primary, -30.0f)};
        c2.setBrightness(this->wrap(primary.getBrightness(), 0.40f, 0.10f, 0.40f));
        c2.setSaturation(this->wrap(primary.getSaturation(), 0.40f, 0.20f, 0.40f));

        HSB c3{this->rotate(primary, -160.0f)};
        c3.setBrightness(this->wrap(primary.getBrightness(), 0.25f, 0.10f, 0.25f));

        HSB c4{this->rotate(primary, -150.0f)};
        c4.setBrightness(this->wrap(primary.getBrightness(), 0.30f, 0.60f, 0.30f));
        c4.setSaturation(this->wrap(primary.getSaturation(), 0.10f, 0.80f, 0.10f));

        HSB c5{this->rotate(primary, -150.0f)};
        c5.setBrightness(this->wrap(primary.getBrightness(), 0.40f, 0.20f, 0.40f));
        c5.setSaturation(this->wrap(primary.getSaturation(), 0.10f, 0.80f, 0.10f));

        this->_colors[0] = std::move(static_cast<T>(primary));
        this->_colors[1] = std::move(static_cast<T>(c1));
        this->_colors[2] = std::move(static_cast<T>(c2));
        this->_colors[3] = std::move(static_cast<T>(c3));
        this->_colors[4] = std::move(static_cast<T>(c4));
        this->_colors[5] = std::move(static_cast<T>(c5));
    }

}

