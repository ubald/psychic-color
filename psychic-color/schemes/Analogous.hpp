#pragma once

#include "ColorWheelScheme.hpp"
#include "../spaces/HSB.hpp"
#include "../PsychicColor.hpp"

namespace psychic_color {

    constexpr std::size_t AnalogousNumColors = 5;

    template<class T>
    class Analogous : public ColorWheelScheme<T, AnalogousNumColors> {
    public:
        explicit Analogous(const T &primaryColor, float angle = 10.0f, bool ryb = false);
        explicit Analogous(const T &primaryColor, bool ryb);
        float getAngle() const;
        void setAngle(float angle);
        void generate() override;
    protected:
        float _angle{10.0f};
    };

    template<class T>
    Analogous<T>::Analogous(const T &primaryColor, const float angle, bool ryb):
        ColorWheelScheme<T, AnalogousNumColors>(primaryColor, ryb), _angle{angle} {
        generate();
    }

    template<class T>
    Analogous<T>::Analogous(const T &primaryColor, bool ryb):
        Analogous<T>(primaryColor, 10.0f, ryb) {}

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
    void Analogous<T>::generate() {
        HSB primary{this->_primaryColor};

        HSB c1{this->rotate(primary, _angle * -2.0f)};
        HSB c2{this->rotate(primary, _angle * -1.0f)};
        HSB c3{this->rotate(primary, _angle * 1.0f)};
        HSB c4{this->rotate(primary, _angle * 2.0f)};

        this->_colors[0] = std::move(static_cast<T>(c1));
        this->_colors[1] = std::move(static_cast<T>(c2));
        this->_colors[2] = std::move(static_cast<T>(primary));
        this->_colors[3] = std::move(static_cast<T>(c3));
        this->_colors[4] = std::move(static_cast<T>(c4));
    }

}

