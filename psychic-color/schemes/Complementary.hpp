#pragma once

#include "ColorWheelScheme.hpp"
#include "../spaces/HSB.hpp"
#include "../PsychicColor.hpp"

namespace psychic_color {

    constexpr std::size_t numColors = 6;

    template<class T>
    class Complementary : public ColorWheelScheme<T, numColors> {
    public:
        explicit Complementary(const T &primaryColor);
    protected:
        void generate() override;
    };

    template<class T>
    Complementary<T>::Complementary(const T &primaryColor):
        ColorWheelScheme<T, numColors>(primaryColor) {
        generate();
    }

    template<class T>
    void Complementary<T>::generate() {
        // PRIMARY
        HSB primary{this->_primaryColor};

        HSB contrasting{primary};
        if (primary.getBrightness() > 40) {
            contrasting.setBrightness(0.1f + primary.getBrightness() * 0.25f);
        } else {
            contrasting.setBrightness(1.0f - primary.getBrightness() * 0.25f);
        }

        HSB supporting{primary};
        supporting.setBrightness(0.3f + primary.getBrightness());
        supporting.setSaturation(0.1f + primary.getSaturation() * 0.3f);

        // COMPLEMENT
        HSB complement{PsychicColor::rybRotate(primary, 180.0f)};

        HSB contrastingComplement{complement};
        if (complement.getBrightness() > 0.3f) {
            contrastingComplement.setBrightness(0.1f + complement.getBrightness() * 0.25f);
        } else {
            contrastingComplement.setBrightness(1.0f - complement.getBrightness() * 0.25f);
        }
        HSB supportingComplement{complement};
        supportingComplement.setBrightness(0.3f + complement.getBrightness());
        supportingComplement.setSaturation(0.1f + complement.getSaturation() * 0.3f);

        this->_colors[0] = std::move(static_cast<T>(primary));
        this->_colors[1] = std::move(static_cast<T>(contrasting));
        this->_colors[2] = std::move(static_cast<T>(supporting));
        this->_colors[3] = std::move(static_cast<T>(complement));
        this->_colors[4] = std::move(static_cast<T>(contrastingComplement));
        this->_colors[5] = std::move(static_cast<T>(supportingComplement));
    }

}

