#include "ARGB.hpp"
#include "RGB.hpp"

namespace psychic_color {

    ARGB::ARGB(const float alpha, const float red, const float green, const float blue) :
        RGB(red, green, blue),
        _alpha(alpha) {}

    ARGB::ARGB(const ARGB &argb) :
        RGB(argb._red, argb._green, argb._blue),
        _alpha(argb._alpha) {}

    ARGB::ARGB(const RGB &rgb) :
        RGB(rgb),
        _alpha(1.0f) {}

    ARGB::ARGB(const unsigned int color) :
        ARGB() {
        setColor(color);
    };

    ARGB::operator RGB() const {
        return RGB(_red, _green, _blue);
    }

    float ARGB::getAlpha() const {
        return _alpha;
    }

    void ARGB::setAlpha(const float alpha) {
        _alpha = std::fmin(std::fmax(0.0f, alpha), 1.0f);
    }

    unsigned int ARGB::getColor() const {
        return (static_cast<unsigned int>(std::round(_alpha * 255.0f)) << 24) | RGB::getColor();
    }

    void ARGB::setColor(const unsigned int color) {
        RGB::setColor(color);
        _alpha = static_cast<float>(color >> 24 & 0xFF) / 255.0f;
    }

    //virtual RGB interpolate( Color &target, const float ratio = 0.5f) const override {
    //    ARGB t = target;
    //    t.setAlpha(_alpha + static_cast<float>(static_cast<float>((t.getAlpha() - _alpha)) * ratio));
    //    t.setRed(_red + static_cast<float>(static_cast<float>((t.getRed() - _red)) * ratio));
    //    t.setGreen(_green + static_cast<float>(static_cast<float>((t.getGreen() - _green)) * ratio));
    //    t.setBlue(_blue + static_cast<float>(static_cast<float>((t.getBlue() - _blue)) * ratio));
    //    return t;
    //}
}
