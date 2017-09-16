#pragma once

#include "ColorWheelScheme.hpp"
#include "../spaces/HSB.hpp"
#include "../PsychicColor.hpp"

namespace psychic_color {

    constexpr std::size_t numColors = 3;

    template<class T>
    class Tetrad : public ColorWheelScheme<T, numColors> {
    public:
        explicit Tetrad(const T &primaryColor, float angle = 120.0f, bool alt = false);
        float getAngle() const;
        void setAngle(float angle);
        bool getAlt() const;
        void setAlt(bool alt);
    protected:
        float _angle{120.0f};
        bool  _alt{false};

        void generate() override;
    };

    template<class T>
    Tetrad<T>::Tetrad(const T &primaryColor, const float angle, bool alt):
        ColorWheelScheme<T, numColors>(primaryColor), _angle{angle}, _alt(alt) {
        generate();
    }

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
    bool Tetrad<T>::getAlt() const {
        return _alt;
    }

    template<class T>
    void Tetrad<T>::setAlt(const bool alt) {
        if (alt != _alt) {
            _alt = alt;
            generate();
        }
    }

    template<class T>
    void Tetrad<T>::generate() {
        float multiplier;

        HSB primary{this->_primaryColor};

        HSB c1{PsychicColor::rybRotate(primary, _angle)};
        if (_alt) {
            multiplier = (0.5f - primary.getBrightness()) / 0.5f;
            c1.brighten(std::min(0.2f, std::max(-0.2f, 0.2f * multiplier)));
        } else if (primary.getBrightness() < 0.5f) {
            c1.brighten(0.2f);
        } else {
            c1.darken(0.2f);
        }

        HSB c2{PsychicColor::rybRotate(primary, _angle * 2.0f)};
        if (_alt) {
            multiplier = (0.5f - primary.getBrightness()) / 0.5f;
            c2.brighten(std::min(0.1f, std::max(-0.1f, 0.1f * multiplier)));
        } else if (primary.getBrightness() > 0.5f) {
            c2.brighten(0.1f);
        } else {
            c2.darken(0.1f);
        }

        _colors[0] = std::move(static_cast<T>(primary));
        _colors[1] = std::move(static_cast<T>(c1));
        _colors[2] = std::move(static_cast<T>(c2));
    }

}

