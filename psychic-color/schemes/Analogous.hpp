#pragma once

#include "ColorWheelScheme.hpp"
#include "../spaces/HSB.hpp"
#include "../PsychicColor.hpp"

namespace psychic_color {

    constexpr std::size_t numColors = 5;

    template<class T>
    class Analogous : public ColorWheelScheme<T, numColors> {
    public:
        explicit Analogous(const T &primaryColor, float angle = 10.0f, float contrast = 0.25f);
        float getAngle() const;
        void setAngle(float angle);
        float getContrast() const;
        void setContrast(float contrast);
    protected:
        float _angle{10.0f};
        float _contrast{25.0f};

        void generate() override;
    };

    template<class T>
    Analogous<T>::Analogous(const T &primaryColor, const float angle, const float contrast):
        ColorWheelScheme<T, numColors>(primaryColor), _angle{angle}, _contrast{contrast} {
        generate();
    }

    template<class T>
    float Analogous<T>::getAngle() const {
        return _angle;
    }

    template<class T>
    void Analogous<T>::setAngle(const float angle) {
        if (angle != _angle) {
            _angle = angle;
            generate();
        }
    }

    template<class T>
    float Analogous<T>::getContrast() const {
        return _contrast;
    }

    template<class T>
    void Analogous<T>::setContrast(const float contrast) {
        if (contrast != _contrast) {
            _contrast = contrast;
            generate();
        }
    }

    template<class T>
    void Analogous<T>::generate() {
        HSB       primaryHSB{this->_primaryColor};
        float     array[4][2] = {
            {1.0f,  2.2f},
            {2.0f,  1.0f},
            {-1.0f, -0.5f},
            {-2.0f, 1.0f}
        };
        for (unsigned int i = 0; i < 4; ++i) {
            float one = array[i][0];
            float two = array[i][1];
            float t   = 0.44f - two * 0.1f;
            HSB newHSB{PsychicColor::rybRotate(primaryHSB, _angle * one)};
            if (primaryHSB.getBrightness() - _contrast * two < t) {
                newHSB.setBrightness(t);
            } else {
                newHSB.setBrightness(primaryHSB.getBrightness() - _contrast * two);
            }
            newHSB.setSaturation(newHSB.getSaturation() - 0.05f);
            this->_colors[i + 1] = std::move(newHSB);
        }
        this->_colors[0] = std::move(primaryHSB);
    }

}

