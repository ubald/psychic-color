#pragma once

#include <array>
#include "spaces/Gray.hpp"
#include "spaces/HSB.hpp"
#include "spaces/HSL.hpp"
#include "spaces/RGB.hpp"
#include "spaces/ARGB.hpp"
#include "spaces/Hex.hpp"

namespace psychic_color {
    class ColorToolkit {

    private:
        static constexpr std::array<std::pair<unsigned int, unsigned int>, 25> rybWheel{{
                                                                                            {0, 0},
                                                                                            {15, 8},
                                                                                            {30, 17},
                                                                                            {45, 26},
                                                                                            {60, 34},
                                                                                            {75, 41},
                                                                                            {90, 48},
                                                                                            {105, 54},
                                                                                            {120, 60},
                                                                                            {135, 81},
                                                                                            {150, 103},
                                                                                            {165, 123},
                                                                                            {180, 138},
                                                                                            {195, 155},
                                                                                            {210, 171},
                                                                                            {225, 187},
                                                                                            {240, 204},
                                                                                            {255, 219},
                                                                                            {270, 234},
                                                                                            {285, 251},
                                                                                            {300, 267},
                                                                                            {315, 282},
                                                                                            {330, 298},
                                                                                            {345, 329},
                                                                                            {360, 0}
                                                                                        }};

    public:
        inline static constexpr unsigned int setColorOpaque(const unsigned int color, const unsigned int opaqueValue = 0xff) noexcept {
            return (opaqueValue << 24) | (color & 0xffffff);
        }

        inline static unsigned int desaturate(const unsigned int color) {
            return Gray{color}.getColor();
        }

        inline static unsigned int getComplement(const unsigned int color) {
            return rybRotate(color, 180);
        }

        static unsigned int shiftBrighteness(const unsigned int color, const float degree) {
            HSB col{color};
            col.brighten(degree);
            return col.getColor();
        }

        static unsigned int shiftSaturation(const unsigned int color, const float degree) {
            HSB col{color};
            col.saturate(degree);
            return col.getColor();
        }

        static unsigned int shiftHue(const unsigned int color, const float degree) {
            HSB col{color};
            col.shiftHue(degree);
            return col.getColor();
        }

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
//
//
//    static rybRotate(unsigned int color, angle:Float)unsigned int 
//    {
//        var hsb:HSB = new HSB().setColor(color);
//
//        var a: Float = 0;
//        for (i in 0...rybWheel.length) {
//            var x0: Int = rybWheel[i][0];
//            var y0: Int = rybWheel[i][1];
//
//            var x1: Int = rybWheel[i + 1][0];
//            var y1: Int = rybWheel[i + 1][1];
//            if(y1 < y0)  y1 += 360;
//            if(y0 <= hsb.hue && hsb.hue <= y1) {
//                a = 1.0 * x0 + (x1 - x0) * (hsb.hue - y0) / (y1 - y0);
//                break;
//            }
//        }
//
//        a = (a + (angle % 360));
//        if (a < 0)  a = 360 + a;
//        if (a > 360)  a = a - 360;
//        a = a % 360;
//
//        var newHue:Float = 0;
//        for (k in 0...rybWheel.length) {
//            var xx0: Int = rybWheel[k][0];
//            var yy0: Int = rybWheel[k][1];
//
//            var xx1: Int = rybWheel[k + 1][0];
//            var yy1: Int = rybWheel[k + 1][1];
//            if (yy1 < yy0) yy1 += 360;
//            if (xx0 <= a && a <= xx1) {
//                newHue = yy0 + (yy1 - yy0) * (a - xx0) / (xx1 - xx0);
//                break;
//            }
//        }
//        hsb.hue = newHue;
//
//        return hsb.getColor();
//    }
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
