#include "Hex.hpp"
#include "RGB.hpp"

namespace psychic_color {

    Hex::Hex(const unsigned int color) :
        Color(),
        _color(color) {}

    Hex::Hex(const Hex &hex) :
        Hex(hex._color) {}

    Hex::operator RGB() const {
        return RGB(getRed(), getGreen(), getBlue());
    }

    unsigned int Hex::getAlpha() const {
        return _color >> 24 & 0xFF;
    }

    void Hex::setAlpha(const unsigned int alpha) {
        if (alpha <= 0) {
            _color &= 0x00FFFFFF;
        } else if (alpha >= 255) {
            _color |= 0xFF000000;
        } else {
            _color = (_color & 0x00FFFFFF) | (alpha << 24);
        }
    }

    unsigned int Hex::getRed() const {
        return _color >> 16 & 0xFF;
    }

    void Hex::setRed(const unsigned int red) {
        if (red <= 0) {
            _color &= 0xFF00FFFF;
        } else if (red >= 255) {
            _color |= 0x00FF0000;
        } else {
            _color = (_color & 0xFF00FFFF) | (red << 16);
        }
    }

    unsigned int Hex::getGreen() const {
        return _color >> 8 & 0xFF;
    }

    void Hex::setGreen(const unsigned int green) {
        if (green <= 0) {
            _color &= 0xFFFF00FF;
        } else if (green >= 255) {
            _color |= 0x0000FF00;
        } else {
            _color = (_color & 0xFFFF00FF) | (green << 8);
        }
    }

    unsigned int Hex::getBlue() const {
        return _color & 0xFF;
    }

    void Hex::setBlue(const unsigned int blue) {
        if (blue <= 0.) {
            _color &= 0xFFFFFF00;
        } else if (blue >= 255) {
            _color |= 0x000000FF;
        } else {
            _color = (_color & 0xFFFFFF00) | blue;
        }
    }

    unsigned int Hex::getColor() const {
        return _color;
    }

    void Hex::setColor(const unsigned int color) {
        _color = color;
    }

    //virtual RGB Hex::interpolate( Color &target, const float ratio = 0.5f) const override {
    //    RGB t = target;
    //    t.setRed(_red + static_cast<float>(static_cast<float>((t.getRed() - _red)) * ratio));
    //    t.setGreen(_green + static_cast<float>(static_cast<float>((t.getGreen() - _green)) * ratio));
    //    t.setBlue(_blue + static_cast<float>(static_cast<float>((t.getBlue() - _blue)) * ratio));
    //    return t;
    //}

}
