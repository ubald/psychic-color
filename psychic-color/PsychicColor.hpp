#pragma once

#include <array>
#include <cmath>
#include "spaces/Gray.hpp"
#include "spaces/HSB.hpp"
#include "spaces/HSL.hpp"
#include "spaces/RGB.hpp"
#include "spaces/ARGB.hpp"
#include "spaces/Hex.hpp"

namespace psychic_color {

    class PsychicColor {

    private:
        static constexpr std::array<std::pair<float, float>, 25> rybWheel{
            {
                {0.f / 360.f, 0.f / 360.f},
                {15.f / 360.f, 8.f / 360.f},
                {30.f / 360.f, 17.f / 360.f},
                {45.f / 360.f, 26.f / 360.f},
                {60.f / 360.f, 34.f / 360.f},
                {75.f / 360.f, 41.f / 360.f},
                {90.f / 360.f, 48.f / 360.f},
                {105.f / 360.f, 54.f / 360.f},
                {120.f / 360.f, 60.f / 360.f},
                {135.f / 360.f, 81.f / 360.f},
                {150.f / 360.f, 103.f / 360.f},
                {165.f / 360.f, 123.f / 360.f},
                {180.f / 360.f, 138.f / 360.f},
                {195.f / 360.f, 155.f / 360.f},
                {210.f / 360.f, 171.f / 360.f},
                {225.f / 360.f, 187.f / 360.f},
                {240.f / 360.f, 204.f / 360.f},
                {255.f / 360.f, 219.f / 360.f},
                {270.f / 360.f, 234.f / 360.f},
                {285.f / 360.f, 251.f / 360.f},
                {300.f / 360.f, 267.f / 360.f},
                {315.f / 360.f, 282.f / 360.f},
                {330.f / 360.f, 298.f / 360.f},
                {345.f / 360.f, 329.f / 360.f},
                {360.f / 360.f, 0.f / 360.f}
            }
        };

    public:
        inline static constexpr unsigned int setColorAlpha(const unsigned int color, const unsigned int opaqueValue = 0xff) noexcept {
            return (opaqueValue << 24) | (color & 0xffffff);
        }

        //inline static unsigned int desaturate(const unsigned int color) {
        //    return Gray{color}.getColor();
        //}
        //
        //inline static unsigned int getComplement(const unsigned int color) {
        //    return rybRotate(color, 180);
        //}
        //
        //static unsigned int shiftBrighteness(const unsigned int color, const float degree) {
        //    HSB col{color};
        //    col.brighten(degree);
        //    return col.getColor();
        //}
        //
        //static unsigned int shiftSaturation(const unsigned int color, const float degree) {
        //    HSB col{color};
        //    col.saturate(degree);
        //    return col.getColor();
        //}
        //
        //static unsigned int shiftHue(const unsigned int color, const float degree) {
        //    HSB col{color};
        //    col.shiftHue(degree);
        //    return col.getColor();
        //}

        //inline static Lab toLab(const unsigned int color) {
        //    return Lab{color};
        //}

        inline static Gray toGray(const unsigned int color) {
            return Gray{color};
        }

        inline static RGB toRGB(const unsigned int color) {
            return RGB{color};
        }

        inline static RGB toARGB(const unsigned int color) {
            return ARGB{color};
        }

        inline static HSB toHSB(const unsigned int color) {
            return HSB{color};
        }

        inline static HSL toHSL(const unsigned int color) {
            return HSL{color};
        }

        //inline static CMYK toCMYK(const unsigned int color) {
        //    return CMYK{color};
        //}

        //inline static XYZ toXYZ(const unsigned int color) {
        //    return XYZ{color};
        //}

        //inline static YUV toYUV(const unsigned int color) {
        //    return YUV{color};
        //}

        inline static Hex toHex(const unsigned int color) {
            return Hex{color};
        }

        //inline static public function toLab(color:Color):Lab
        //{
        //    return new Lab().fromRGB(color.toRGB());
        //}
        //
        //inline static public function toGray(color:Color):Gray
        //{
        //    return new Gray().fromRGB(color.toRGB());
        //}
        //
        //inline static public function toHSB(color:Color):HSB
        //{
        //    return new HSB().fromRGB(color.toRGB());
        //}
        //
        //inline static public function toHSL(color:Color):HSL
        //{
        //    return new HSL().fromRGB(color.toRGB());
        //}
        //
        //inline static public function toCMYK(color:Color):CMYK
        //{
        //    return new CMYK().fromRGB(color.toRGB());
        //}
        //
        //inline static public function toXYZ(color:Color):XYZ
        //{
        //    return new XYZ().fromRGB(color.toRGB());
        //}
        //
        //inline static public function toYUV(color:Color):YUV
        //{
        //    return new YUV().fromRGB(color.toRGB());
        //}
        //
        //inline static public function toARGB(color:Color):ARGB
        //{
        //    return new ARGB().fromRGB(color.toRGB());
        //}
        //
        //inline static public function toHex(color:Color):Hex
        //{
        //    return new Hex(color.getColor());
        //}

        //inline static unsigned intAnalogous<Hex> {getAnalogousScheme(color, ?angle: Float = 10, ?contrast:Float = 25)
        //    return new Analogous<Hex>(new Hex(color), angle, contrast);
        //}

        //inline static Complementary <Hex> getComplementaryScheme(unsigned intcolor)
        //    return new Complementary<Hex>(new Hex(color));
        //}

        //inline static Compound <Hex> getCompoundScheme(unsigned intcolor)
        //    return new Compound<Hex>(new Hex(color));
        //}

        //inline static FlippedCompound <Hex> getFlippedCompoundScheme(unsigned intcolor)
        //    return new FlippedCompound<Hex>(new Hex(color));
        //}

        //inline static Monochrome <Hex> getMonochromeScheme(unsigned intcolor)
        //    return new Monochrome<Hex>(new Hex(color));
        //}

        //inline static SplitComplementary <Hex> getSplitComplementaryScheme(unsigned intcolor)
        //    return new SplitComplementary<Hex>(new Hex(color));
        //}

        //inline static Tetrad <Hex> { getTetradScheme(unsigned intcolor, ?angle:Float = 90, ?alt:Bool = false)
        //    return new Tetrad<Hex>(new Hex(color), angle, alt);
        //}

        //inline static Triad <Hex> getTriadScheme(unsigned intcolor, ?angle:Float = 120) {
        //        return new Triad<Hex>(new Hex(color), angle);
        //}

        inline static constexpr float mapRange(float value, float fromLower, float fromUpper, float toLower, float toUpper) {
            return (toLower + (value - fromLower) * ((toUpper - toLower) / (fromUpper - fromLower)));
        };

        // These two functions are ripped straight from Kuler source.
        // They convert between scientific hue to the color wheel's "artistic" hue.
        static float artisticToScientificSmooth(float hue) {
            hue = std::fmod(hue, 360.0f);
            return (
                hue < 60.0f ? hue * (35.0f / 60.0f) :
                hue < 122.0f ? mapRange(hue, 60.0f, 122.0f, 35.0f, 60.0f) :
                hue < 165.0f ? mapRange(hue, 122.0f, 165.0f, 60.0f, 120.0f) :
                hue < 218.0f ? mapRange(hue, 165.0f, 218.0f, 120.0f, 180.0f) :
                hue < 275.0f ? mapRange(hue, 218.0f, 275.0f, 180.0f, 240.0f) :
                hue < 330.0f ? mapRange(hue, 275.0f, 330.0f, 240.0f, 300.0f) :
                mapRange(hue, 330.0f, 360.0f, 300.0f, 360.0f)
            );
        };

        static float scientificToArtisticSmooth(float hue) {
            hue = std::fmod(hue, 360.0f);
            return (
                hue < 35.0f ? hue * (60.0f / 35.0f) :
                hue < 60.0f ? mapRange(hue, 35.0f, 60.0f, 60.0f, 122.0f) :
                hue < 120.0f ? mapRange(hue, 60.0f, 120.0f, 122.0f, 165.0f) :
                hue < 180.0f ? mapRange(hue, 120.0f, 180.0f, 165.0f, 218.0f) :
                hue < 240.0f ? mapRange(hue, 180.0f, 240.0f, 218.0f, 275.0f) :
                hue < 300.0f ? mapRange(hue, 240.0f, 300.0f, 275.0f, 330.0f) :
                mapRange(hue, 300.0f, 360.0f, 330.0f, 360.0f)
            );
        };

        static HSB rybRotate(HSB hsb, float angle) {
            hsb.setHueAngle(artisticToScientificSmooth(scientificToArtisticSmooth(hsb.getHueAngle()) + angle));
            return hsb;
        }

//
//        static HSB rybRotate(HSB hsb, float angle) {
//            float a = 0.0f;
//
//            for (unsigned int i = 0; i < rybWheel.size() - 1; ++i) {
//                float x0 = rybWheel[i].first;
//                float y0 = rybWheel[i].second;
//                float x1 = rybWheel[i + 1].first;
//                float y1 = rybWheel[i + 1].second;
//                if (y1 < y0) {
//                    y1 += 1.0f;
//                }
//                if (y0 <= hsb.getHue() && hsb.getHue() <= y1) {
//                    a = 1.0f * x0 + (x1 - x0) * (hsb.getHue() - y0) / (y1 - y0);
//                    break;
//                }
//            }
//
//            a = (a + (std::fmod(angle, 1.0f)));
//            if (a < 0) {
//                a = 1.0f + a;
//            }
//            if (a > 1.0f) {
//                a = a - 1.0f;
//            }
//            a = std::fmod(a, 1.0f);
//            std::cout << a << std::endl;
//
//            float newHue = 0.0f;
//
//            for (unsigned int i = 0; i < rybWheel.size() - 1; ++i) {
//                float x0 = rybWheel[i].first;
//                float y0 = rybWheel[i].second;
//                float x1 = rybWheel[i + 1].first;
//                float y1 = rybWheel[i + 1].second;
//                if (y1 < y0) {
//                    y1 += 1.0f;
//                }
//                if (x0 <= a && a <= x1) {
//                    newHue = y0 + (y1 - y0) * (a - x0) / (x1 - x0);
//                    break;
//                }
//            }
//
//            hsb.setHue(newHue);
//
//            return hsb;
//        }

        template<class T>
        static HSB rybRotate(const T &color, float angle) {
            HSB hsb{color};
            return rybRotate(std::move(hsb), angle);
        }
//
//    static public function Array<Int> { intArray(colors:ColorScheme<Dynamic>)
//        var a = [];
//        for (c in colors) {
//            a.push(c.getColor());
//        }
//        return a;
//    }
//}
//
    };
}
