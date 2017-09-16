#include <iostream>
#include "RGB.hpp"
#include "ARGB.hpp"

namespace psychic_color {

    RGB::RGB(const float red, const float green, const float blue) :
        Color(),
        _red(red), _green(green), _blue(blue) {}

    RGB::RGB(const RGB &rgb) :
        RGB(rgb._red, rgb._green, rgb._blue) {}

    RGB::RGB(const unsigned int color) :
        RGB() {
        setColor(color);
    };

    RGB::operator RGB() const {
        return RGB(_red, _green, _blue);
    }

    float RGB::getRed() const {
        return _red;
    }

    void RGB::setRed(const float red) {
        _red = std::fmin(std::fmax(0.0f, red), 1.0f);
    }

    float RGB::getGreen() const {
        return _green;
    }

    void RGB::setGreen(const float green) {
        _green = std::fmin(std::fmax(0.0f, green), 1.0f);
    }

    float RGB::getBlue() const {
        return _blue;
    }

    void RGB::setBlue(const float blue) {
        _blue = std::fmin(std::fmax(0.0f, blue), 1.0f);
    }

    unsigned int RGB::getColor() const {
        return (static_cast<unsigned int>(std::round(_red * 255.0f)) << 16)
               | (static_cast<unsigned int>(std::round(_green * 255.0f)) << 8)
               | static_cast<unsigned int>(std::round(_blue * 255.0f));
    }

    void RGB::setColor(const unsigned int color) {
        _red   = static_cast<float>(color >> 16 & 0xFF) / 255.0f;
        _green = static_cast<float>(color >> 8 & 0xFF) / 255.0f;
        _blue  = static_cast<float>(color & 0xFF) / 255.0f;
    }

    //virtual RGB RGB::interpolate( Color &target, const float ratio = 0.5f) const override {
    //    RGB t = target;
    //    t.setRed(_red + static_cast<float>(static_cast<float>((t.getRed() - _red)) * ratio));
    //    t.setGreen(_green + static_cast<float>(static_cast<float>((t.getGreen() - _green)) * ratio));
    //    t.setBlue(_blue + static_cast<float>(static_cast<float>((t.getBlue() - _blue)) * ratio));
    //    return t;
    //}


}
