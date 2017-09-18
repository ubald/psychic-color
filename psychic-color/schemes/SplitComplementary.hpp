#pragma once

#include "ColorWheelScheme.hpp"
#include "../spaces/HSB.hpp"
#include "../PsychicColor.hpp"

namespace psychic_color {

    constexpr std::size_t SplitComplementaryNumColors = 3;

    template<class T>
    class SplitComplementary : public ColorWheelScheme<T, SplitComplementaryNumColors> {
    public:
        explicit SplitComplementary(const T &primaryColor, float angle = 30.0f, bool ryb = false);
        explicit SplitComplementary(const T &primaryColor, bool ryb);
        float getAngle() const;
        void setAngle(float angle);
        void generate() override;
    protected:
        float _angle{30.0f};
    };

    template<class T>
    SplitComplementary<T>::SplitComplementary(const T &primaryColor, const float angle, bool ryb):
        ColorWheelScheme<T, SplitComplementaryNumColors>(primaryColor, ryb), _angle(angle) {
        generate();
    }

    template<class T>
    SplitComplementary<T>::SplitComplementary(const T &primaryColor, bool ryb):
        SplitComplementary<T>(primaryColor, 30.0f, ryb) {}

    template<class T>
    float SplitComplementary<T>::getAngle() const {
        return _angle;
    }

    template<class T>
    void SplitComplementary<T>::setAngle(const float angle) {
        if (angle != _angle) {
            _angle = angle;
            generate();
        }
    }

    template<class T>
    void SplitComplementary<T>::generate() {
        HSB primary{this->_primaryColor};

        HSB c1{this->rotate(primary, 180.0f - _angle)};
        //c1.brighten(0.1f);

        HSB c2{this->rotate(primary, 180.0f + _angle)};
        //c2.brighten(0.1f);

        this->_colors[0] = std::move(static_cast<T>(primary));
        this->_colors[1] = std::move(static_cast<T>(c1));
        this->_colors[2] = std::move(static_cast<T>(c2));
    }

}

