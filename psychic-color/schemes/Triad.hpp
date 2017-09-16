#pragma once

#include "ColorWheelScheme.hpp"
#include "../spaces/HSB.hpp"
#include "../PsychicColor.hpp"

namespace psychic_color {

    constexpr std::size_t numColors = 3;

    template<class T>
    class Triad : public ColorWheelScheme<T, numColors> {
    public:
        explicit Triad(const T &primaryColor, float angle = 120.0f);
        float getAngle() const;
        void setAngle(float angle);
    protected:
        float _angle{120.0f};

        void generate() override;
    };

    template<class T>
    Triad<T>::Triad(const T &primaryColor, const float angle):
        ColorWheelScheme<T, numColors>(primaryColor), _angle{angle} {
        generate();
    }

    template<class T>
    float Triad<T>::getAngle() const {
        return _angle;
    }

    template<class T>
    void Triad<T>::setAngle(const float angle) {
        if (angle != _angle) {
            _angle = angle;
            generate();
        }
    }

    template<class T>
    void Triad<T>::generate() {
        HSB primary{this->_primaryColor};

        HSB c1{PsychicColor::rybRotate(primary, _angle)};
        c1.brighten(0.1f);

        HSB c2{PsychicColor::rybRotate(primary, -_angle)};
        c2.brighten(0.1f);

        _colors[0] = std::move(primary);
        _colors[1] = std::move(c1);
        _colors[2] = std::move(c2);
    }

}

