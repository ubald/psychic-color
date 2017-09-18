#include "HSL.hpp"
#include "RGB.hpp"

namespace psychic_color {

    inline float HSL::hue2rgb(const float p, const float q, float t) {
        if (t < 0.0f) { t += 1.0f; }
        if (t > 1.0f) { t -= 1.0f; }
        if (t < 1.0f / 6.0f) { return p + (q - p) * 6.0f * t; }
        if (t < 1.0f / 2.0f) { return q; }
        if (t < 2.0f / 3.0f) { return p + (q - p) * (2.0f / 3.0f - t) * 6.0f; }
        return p;
    }

    HSL::HSL() : HSL(0.0f, 0.0f, 0.0f) {}

    HSL::HSL(const float hue, const float saturation, const float lightness) :
        Color(),
        _hue(hue), _saturation(saturation), _lightness(lightness) {}

    HSL::HSL(const HSL &hsl) :
        HSL(hsl._hue, hsl._saturation, hsl._lightness) {}

    HSL::HSL(const unsigned int color) :
        HSL() {
        setColor(color);
    }

    HSL::HSL(const RGB &rgb) :
        HSL() {
        float r = rgb.getRed();
        float g = rgb.getGreen();
        float b = rgb.getBlue();

        float max = std::max(r, std::max(g, b));
        float min = std::min(r, std::min(g, b));
        float h, s, l;

        h = s = l = (max + min) / 2.0f;

        if (max == min) {
            h = s = 0;
        } else {
            float d = max - min;
            s = l > 0.5f ? d / (2.0f - max - min) : d / (max + min);
            if (max == r) {
                h = (g - b) / d + (g < b ? 6.0f : 0.0f);
            } else if (max == g) {
                h = (b - r) / d + 2.0f;
            } else { //if (maxe == b)
                h = (r - g) / d + 4.0f;
            }
            h /= 6.0f;
        }

        _hue        = h;
        _saturation = s;
        _lightness  = l;
    }

    HSL::operator RGB() const {
        float r, g, b;

        if (_saturation == 0.0f) {
            r = g = b = _lightness; // achromatic
        } else {
            float q = _lightness < 0.5f
                      ? _lightness * (1.0f + _saturation)
                      : _lightness + _saturation - _lightness * _saturation;
            float p = 2.0f * _lightness - q;
            r = hue2rgb(p, q, _hue + 1.0f / 3.0f);
            g = hue2rgb(p, q, _hue);
            b = hue2rgb(p, q, _hue - 1.0f / 3.0f);
        }

        return RGB(r, g, b);
    }

    float HSL::getHue() const {
        return _hue;
    }

    void HSL::setHue(const float hue) {
        float h = hue;

        if (h < 0.0f) {
            h = 1.0f + std::fmod(h, 1.0f);
        }

        if (h >= 1.0f) {
            h = std::fmod(h, 1.0f);
        }

        _hue = h;
    }

    void HSL::shiftHue(const float hue) {
        setHue(_hue + hue);
    }

    float HSL::getHueAngle() const {
        return _hue * 360.0f;
    }

    void HSL::setHueAngle(const float hue) {
        setHue(hue / 360.0f);
    }

    void HSL::shiftHueAngle(const float hue) {
        setHue(_hue + (hue / 360.0f));
    }

    float HSL::getSaturation() const {
        return _saturation;
    }

    void HSL::setSaturation(const float saturation) {
        _saturation = std::fmin(std::fmax(0.0f, saturation), 1.0f);
    }

    void HSL::saturate(const float saturation) {
        _saturation = std::fmin(std::fmax(0.0f, _saturation + saturation), 1.0f);
    }

    void HSL::desaturate(const float saturation) {
        _saturation = std::fmin(std::fmax(0.0f, _saturation - saturation), 1.0f);
    }

    float HSL::getLightness() const {
        return _lightness;
    }

    void HSL::setLightness(const float lightness) {
        _lightness = std::fmin(std::fmax(0.0f, lightness), 1.0f);
    }

    void HSL::lighten(const float lightness) {
        _lightness = std::fmin(std::fmax(0.0f, _lightness + lightness), 1.0f);
    }

    void HSL::darken(const float lightness) {
        _lightness = std::fmin(std::fmax(0.0f, _lightness - lightness), 1.0f);
    }

    unsigned int HSL::getColor() const {
        RGB rgb{*this};
        return rgb.getColor();
    }

    void HSL::setColor(const unsigned int color) {
        // TODO: This is fat from ideal
        HSL hsl{RGB(color)};
        _hue        = hsl.getHue();
        _saturation = hsl.getSaturation();
        _lightness  = hsl.getLightness();
    }

}
