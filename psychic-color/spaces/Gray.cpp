#include "Gray.hpp"
#include "RGB.hpp"

namespace psychic_color {

    inline float Gray::rgbToGray(float red, float green, float blue) {
        return 0.3f * red + 0.59f * green + 0.11f * blue;
    }

    Gray::Gray(float gray) :
        Color(),
        _gray(gray) {}

    Gray::Gray(const Gray &gray) :
        Gray(gray._gray) {}

    Gray::Gray(const RGB &rgb) :
        Gray(rgbToGray(rgb.getRed(), rgb.getGreen(), rgb.getBlue())) {}

    Gray::Gray(const unsigned int color) :
        Gray() {
        setColor(color);
    }

    Gray::operator RGB() const {
        return RGB(_gray, _gray, _gray);
    }

    float Gray::getGray() const {
        return _gray;
    }

    void Gray::setGray(const float gray) {
        _gray = std::fmin(std::fmax(0.0f, gray), 1.0f);
    }

    unsigned int Gray::getColor() const {
        unsigned int g = static_cast<unsigned int>(std::round(_gray * 255.0f));
        return (g << 16) | (g << 8) | g;
    }

    void Gray::setColor(const unsigned int color) {
        _gray = rgbToGray(
            static_cast<float>(color >> 16 & 0xFF) / 255.0f,
            static_cast<float>(color >> 8 & 0xFF) / 255.0f,
            static_cast<float>(color & 0xFF) / 255.0f
        );
    }

    //virtual Gray Gray::interpolate( Color &target, const float ratio = 0.5f) const override {
    //    Gray t = target;
    //    t.setGray(_gray + static_cast<float>(static_cast<float>((t.getGray() - _gray)) * ratio));
    //    return t;
    //}

}
