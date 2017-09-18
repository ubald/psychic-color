#include "HSB.hpp"
#include "RGB.hpp"

namespace psychic_color {

    HSB::HSB() : HSB(0.0f, 0.0f, 0.0f) {}

    HSB::HSB(const float hue, const float saturation, const float brightness) :
        Color(),
        _hue(hue), _saturation(saturation), _brightness(brightness) {}

    HSB::HSB(const HSB &hsb) :
        HSB(hsb._hue, hsb._saturation, hsb._brightness) {}

    HSB::HSB(const unsigned int color) :
        HSB() {
        setColor(color);
    }

    HSB::HSB(const RGB &rgb) :
        HSB() {
        float r = rgb.getRed();
        float g = rgb.getGreen();
        float b = rgb.getBlue();

        float min = std::fmin(r, std::fmin(g, b));
        float max = std::fmax(r, std::fmax(g, b));

        float v = max;

        float delta = max - min;

        float s;
        float h;

        if (max != 0.0f) {
            s = (delta / max);
        } else {
            s = 0;
            h = -1;

            _hue        = h;
            _saturation = s;
            _brightness = v;
            return;
        }

        if (delta == 0.0f) {
            _hue        = 0;
            _saturation = s;
            _brightness = v;
            return;
        }

        if (r == max) {
            h = (g - b) / delta;
        } else if (g == max) {
            h = 2 + (b - r) / delta;
        } else {
            h = 4 + (r - g) / delta;
        }

        h /= 6.0f;
        if (h < 0.0f) {
            h += 1.0f;
        }

        _hue        = h;
        _saturation = s;
        _brightness = v;
    }

    HSB::operator RGB() const {
        float hue        = std::fmod(_hue, 1.0f);
        float saturation = _saturation;
        float brightness = _brightness;
        float r          = 0.0f, g = 0.0f, b = 0.0f;

        if (brightness == 0.0f) {
            return RGB();
        }

        hue *= 6;

        int   i = static_cast<int>(std::floor(hue));
        float f = hue - i;
        float p = brightness * (1.0f - saturation);
        float q = brightness * (1.0f - (saturation * f));
        float t = brightness * (1.0f - (saturation * (1.0f - f)));

        if (i == 0) {
            r = brightness;
            g = t;
            b = p;
        } else if (i == 1) {
            r = q;
            g = brightness;
            b = p;
        } else if (i == 2) {
            r = p;
            g = brightness;
            b = t;
        } else if (i == 3) {
            r = p;
            g = q;
            b = brightness;
        } else if (i == 4) {
            r = t;
            g = p;
            b = brightness;
        } else if (i == 5) {
            r = brightness;
            g = p;
            b = q;
        }

        return RGB(r, g, b);
    }

    float HSB::getHue() const {
        return _hue;
    }

    void HSB::setHue(const float hue) {
        float h = hue;

        if (h < 0.0f) {
            h = 1.0f + std::fmod(h, 1.0f);
        }

        if (h >= 1.0f) {
            h = std::fmod(h, 1.0f);
        }

        _hue = h;
    }

    void HSB::shiftHue(const float hue) {
        setHue(_hue + hue);
    }

    float HSB::getHueAngle() const {
        return _hue * 360.0f;
    }

    void HSB::setHueAngle(const float hue) {
        setHue(hue / 360.0f);
    }

    void HSB::shiftHueAngle(const float hue) {
        setHue(_hue + (hue / 360.0f));
    }

    float HSB::getSaturation() const {
        return _saturation;
    }

    void HSB::setSaturation(const float saturation) {
        _saturation = std::fmin(std::fmax(0.0f, saturation), 1.0f);
    }

    void HSB::saturate(const float saturation) {
        _saturation = std::fmin(std::fmax(0.0f, _saturation + saturation), 1.0f);
    }

    void HSB::desaturate(const float saturation) {
        _saturation = std::fmin(std::fmax(0.0f, _saturation - saturation), 1.0f);
    }

    float HSB::getBrightness() const {
        return _brightness;
    }

    void HSB::setBrightness(const float brightness) {
        _brightness = std::fmin(std::fmax(0.0f, brightness), 1.0f);
    }

    void HSB::brighten(const float brightness) {
        _brightness = std::fmin(std::fmax(0.0f, _brightness + brightness), 1.0f);
    }

    void HSB::darken(const float brightness) {
        _brightness = std::fmin(std::fmax(0.0f, _brightness - brightness), 1.0f);
    }

    unsigned int HSB::getColor() const {
        RGB rgb{*this};
        return rgb.getColor();
    }

    void HSB::setColor(const unsigned int color) {
        // TODO: This is fat from ideal
        HSB hsb{RGB(color)};
        _hue        = hsb.getHue();
        _saturation = hsb.getSaturation();
        _brightness = hsb.getBrightness();
    }

}
