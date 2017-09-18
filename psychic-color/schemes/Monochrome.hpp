#pragma once

#include "ColorScheme.hpp"
#include "../spaces/HSB.hpp"
#include "../PsychicColor.hpp"

namespace psychic_color {

    constexpr std::size_t MonochromeNumColors = 5;

    template<class T>
    class Monochrome : public ColorScheme<T, MonochromeNumColors> {
    public:
        explicit Monochrome(const T &primaryColor, float contrast = 0.25f);
        float getContrast() const;
        void setContrast(float contrast);
        void generate() override;
    protected:
        float _contrast{25.0f};
    };

    template<class T>
    Monochrome<T>::Monochrome(const T &primaryColor, float contrast):
        ColorScheme<T, MonochromeNumColors>(primaryColor), _contrast(contrast) {
        generate();
    }

    template<class T>
    float Monochrome<T>::getContrast() const {
        return _contrast;
    }

    template<class T>
    void Monochrome<T>::setContrast(const float contrast) {
        if (contrast != _contrast) {
            _contrast = contrast;
            generate();
        }
    }

    template<class T>
    void Monochrome<T>::generate() {
        HSB primary{this->_primaryColor};

        HSB c1{primary};
        c1.brighten(_contrast);
        //c1.setBrightness(this->wrap(primary.getBrightness(), 0.50f, 0.20f, 0.30f));
        //c1.setSaturation(this->wrap(primary.getSaturation(), 0.30f, 0.10f, 0.20f));

        HSB c2{primary};
        c2.darken(_contrast);
        //c2.setBrightness(this->wrap(primary.getBrightness(), 0.20f, 0.20f, 0.60f));

        HSB c3{primary};
        c3.saturate(_contrast);
        //c3.setBrightness(std::max(0.2f, primary.getBrightness() + (1.0f - primary.getBrightness()) * 0.2f));
        //c3.setSaturation(this->wrap(primary.getSaturation(), 0.30f, 0.10f, 0.30f));

        HSB c4{primary};
        c4.desaturate(_contrast);
        //c4.setBrightness(this->wrap(primary.getBrightness(), 0.50f, 0.20f, 0.30f));

        this->_colors[0] = std::move(static_cast<T>(primary));
        this->_colors[1] = std::move(static_cast<T>(c1));
        this->_colors[2] = std::move(static_cast<T>(c2));
        this->_colors[3] = std::move(static_cast<T>(c3));
        this->_colors[4] = std::move(static_cast<T>(c4));
    }

}

