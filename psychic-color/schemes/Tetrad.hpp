#pragma once

#include "ColorWheelScheme.hpp"
#include "../spaces/HSB.hpp"
#include "../PsychicColor.hpp"

namespace psychic_color {

    constexpr std::size_t TetradNumColors = 4;

    template<class T>
    class Tetrad : public ColorWheelScheme<T, TetradNumColors> {
    public:
        explicit Tetrad(const T &primaryColor, float angle = 90.0f, bool ryb = false);
        Tetrad(const T &primaryColor, bool ryb);
        float getAngle() const;
        void setAngle(float angle);
        void generate() override;
    protected:
        float _angle{90.0f};
    };

    template<class T>
    Tetrad<T>::Tetrad(const T &primaryColor, const float angle, bool ryb):
        ColorWheelScheme<T, TetradNumColors>(primaryColor, ryb), _angle{angle} {
        generate();
    }

    template<class T>
    Tetrad<T>::Tetrad(const T &primaryColor, bool ryb):
        Tetrad<T>(primaryColor, 90.0f, ryb) {}

    template<class T>
    float Tetrad<T>::getAngle() const {
        return _angle;
    }

    template<class T>
    void Tetrad<T>::setAngle(const float angle) {
        if (angle != _angle) {
            _angle = angle;
            generate();
        }
    }

    template<class T>
    void Tetrad<T>::generate() {
        //float multiplier;

        HSB primary{this->_primaryColor};

        HSB c1{this->rotate(primary, _angle)};
        // TODO: Adjust brightness according to hue's perceived luminosity
        //if (_alt) {
        //    multiplier = (0.5f - primary.getBrightness()) / 0.5f;
        //    c1.brighten(std::min(0.2f, std::max(-0.2f, 0.2f * multiplier)));
        //} else if (primary.getBrightness() < 0.5f) {
        //    c1.brighten(0.2f);
        //} else {
        //    c1.darken(0.2f);
        //}

        HSB c2{this->rotate(primary, 180.0f)};
        // TODO: Adjust brightness according to hue's perceived luminosity
        //if (_alt) {
        //    multiplier = (0.5f - primary.getBrightness()) / 0.5f;
        //    c2.brighten(std::min(0.1f, std::max(-0.1f, 0.1f * multiplier)));
        //} else if (primary.getBrightness() > 0.5f) {
        //    c2.brighten(0.1f);
        //} else {
        //    c2.darken(0.1f);
        //}

        HSB c3{this->rotate(primary, 180.0f + _angle)};
        // TODO: Adjust brightness according to hue's perceived luminosity
        //c3.brighten(0.1f);

        this->_colors[0] = std::move(static_cast<T>(primary));
        this->_colors[1] = std::move(static_cast<T>(c1));
        this->_colors[2] = std::move(static_cast<T>(c2));
        this->_colors[3] = std::move(static_cast<T>(c3));
    }

}

