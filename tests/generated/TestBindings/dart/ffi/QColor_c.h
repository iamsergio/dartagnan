#include "TestBindings_exports.h"
#include <qcolor.h>
#include <qlist.h>
#include <qstring.h>
#include <qvariant.h>

namespace TestBindings_wrappersNS {
class QColor_wrapper : public ::QColor
{
public:
    ~QColor_wrapper();
    QColor_wrapper();
    QColor_wrapper(const QString &name);
    QColor_wrapper(const char *aname);
    QColor_wrapper(int r, int g, int b, int a = 255);
    int alpha() const;
    float alphaF() const;
    int black() const;
    float blackF() const;
    int blue() const;
    float blueF() const;
    static QList<QString> colorNames();
    int cyan() const;
    float cyanF() const;
    QColor darker(int f = 200) const;
    static QColor fromCmyk(int c, int m, int y, int k, int a = 255);
    static QColor fromCmykF(float c, float m, float y, float k, float a = 1.0);
    static QColor fromHsl(int h, int s, int l, int a = 255);
    static QColor fromHslF(float h, float s, float l, float a = 1.0);
    static QColor fromHsv(int h, int s, int v, int a = 255);
    static QColor fromHsvF(float h, float s, float v, float a = 1.0);
    static QColor fromRgb(int r, int g, int b, int a = 255);
    static QColor fromRgbF(float r, float g, float b, float a = 1.0);
    int green() const;
    float greenF() const;
    int hslHue() const;
    float hslHueF() const;
    int hslSaturation() const;
    float hslSaturationF() const;
    int hsvHue() const;
    float hsvHueF() const;
    int hsvSaturation() const;
    float hsvSaturationF() const;
    int hue() const;
    float hueF() const;
    bool isValid() const;
    static bool isValidColor(const QString &name);
    QColor lighter(int f = 150) const;
    int lightness() const;
    float lightnessF() const;
    int magenta() const;
    float magentaF() const;
    QString name() const;
    int red() const;
    float redF() const;
    int saturation() const;
    float saturationF() const;
    void setAlpha(int alpha);
    void setAlphaF(float alpha);
    void setBlue(int blue);
    void setBlueF(float blue);
    void setCmyk(int c, int m, int y, int k, int a = 255);
    void setCmykF(float c, float m, float y, float k, float a = 1.0);
    void setGreen(int green);
    void setGreenF(float green);
    void setHsl(int h, int s, int l, int a = 255);
    void setHslF(float h, float s, float l, float a = 1.0);
    void setHsv(int h, int s, int v, int a = 255);
    void setHsvF(float h, float s, float v, float a = 1.0);
    void setNamedColor(const QString &name);
    void setRed(int red);
    void setRedF(float red);
    void setRgb(int r, int g, int b, int a = 255);
    void setRgbF(float r, float g, float b, float a = 1.0);
    QColor toCmyk() const;
    QColor toExtendedRgb() const;
    QColor toHsl() const;
    QColor toHsv() const;
    QColor toRgb() const;
    int value() const;
    float valueF() const;
    int yellow() const;
    float yellowF() const;
};
}
extern "C" {
// QColor::QColor()
TestBindings_EXPORT void *c_QColor__constructor();
// QColor::QColor(const QString & name)
TestBindings_EXPORT void *c_QColor__constructor_QString(const char *name_);
// QColor::QColor(const char * aname)
TestBindings_EXPORT void *c_QColor__constructor_char(const char *aname);
// QColor::QColor(int r, int g, int b, int a)
TestBindings_EXPORT void *c_QColor__constructor_int_int_int_int(int r, int g, int b, int a);
// QColor::alpha() const
TestBindings_EXPORT int c_QColor__alpha(void *thisObj);
// QColor::alphaF() const
TestBindings_EXPORT float c_QColor__alphaF(void *thisObj);
// QColor::black() const
TestBindings_EXPORT int c_QColor__black(void *thisObj);
// QColor::blackF() const
TestBindings_EXPORT float c_QColor__blackF(void *thisObj);
// QColor::blue() const
TestBindings_EXPORT int c_QColor__blue(void *thisObj);
// QColor::blueF() const
TestBindings_EXPORT float c_QColor__blueF(void *thisObj);
// QColor::colorNames()
TestBindings_EXPORT void *c_static_QColor__colorNames();
// QColor::cyan() const
TestBindings_EXPORT int c_QColor__cyan(void *thisObj);
// QColor::cyanF() const
TestBindings_EXPORT float c_QColor__cyanF(void *thisObj);
// QColor::darker(int f) const
TestBindings_EXPORT void *c_QColor__darker_int(void *thisObj, int f);
// QColor::fromCmyk(int c, int m, int y, int k, int a)
TestBindings_EXPORT void *c_static_QColor__fromCmyk_int_int_int_int_int(int c, int m, int y, int k,
                                                                        int a);
// QColor::fromCmykF(float c, float m, float y, float k, float a)
TestBindings_EXPORT void *c_static_QColor__fromCmykF_float_float_float_float_float(float c, float m,
                                                                                   float y, float k,
                                                                                   float a);
// QColor::fromHsl(int h, int s, int l, int a)
TestBindings_EXPORT void *c_static_QColor__fromHsl_int_int_int_int(int h, int s, int l, int a);
// QColor::fromHslF(float h, float s, float l, float a)
TestBindings_EXPORT void *c_static_QColor__fromHslF_float_float_float_float(float h, float s,
                                                                            float l, float a);
// QColor::fromHsv(int h, int s, int v, int a)
TestBindings_EXPORT void *c_static_QColor__fromHsv_int_int_int_int(int h, int s, int v, int a);
// QColor::fromHsvF(float h, float s, float v, float a)
TestBindings_EXPORT void *c_static_QColor__fromHsvF_float_float_float_float(float h, float s,
                                                                            float v, float a);
// QColor::fromRgb(int r, int g, int b, int a)
TestBindings_EXPORT void *c_static_QColor__fromRgb_int_int_int_int(int r, int g, int b, int a);
// QColor::fromRgbF(float r, float g, float b, float a)
TestBindings_EXPORT void *c_static_QColor__fromRgbF_float_float_float_float(float r, float g,
                                                                            float b, float a);
// QColor::green() const
TestBindings_EXPORT int c_QColor__green(void *thisObj);
// QColor::greenF() const
TestBindings_EXPORT float c_QColor__greenF(void *thisObj);
// QColor::hslHue() const
TestBindings_EXPORT int c_QColor__hslHue(void *thisObj);
// QColor::hslHueF() const
TestBindings_EXPORT float c_QColor__hslHueF(void *thisObj);
// QColor::hslSaturation() const
TestBindings_EXPORT int c_QColor__hslSaturation(void *thisObj);
// QColor::hslSaturationF() const
TestBindings_EXPORT float c_QColor__hslSaturationF(void *thisObj);
// QColor::hsvHue() const
TestBindings_EXPORT int c_QColor__hsvHue(void *thisObj);
// QColor::hsvHueF() const
TestBindings_EXPORT float c_QColor__hsvHueF(void *thisObj);
// QColor::hsvSaturation() const
TestBindings_EXPORT int c_QColor__hsvSaturation(void *thisObj);
// QColor::hsvSaturationF() const
TestBindings_EXPORT float c_QColor__hsvSaturationF(void *thisObj);
// QColor::hue() const
TestBindings_EXPORT int c_QColor__hue(void *thisObj);
// QColor::hueF() const
TestBindings_EXPORT float c_QColor__hueF(void *thisObj);
// QColor::isValid() const
TestBindings_EXPORT bool c_QColor__isValid(void *thisObj);
// QColor::isValidColor(const QString & name)
TestBindings_EXPORT bool c_static_QColor__isValidColor_QString(const char *name_);
// QColor::lighter(int f) const
TestBindings_EXPORT void *c_QColor__lighter_int(void *thisObj, int f);
// QColor::lightness() const
TestBindings_EXPORT int c_QColor__lightness(void *thisObj);
// QColor::lightnessF() const
TestBindings_EXPORT float c_QColor__lightnessF(void *thisObj);
// QColor::magenta() const
TestBindings_EXPORT int c_QColor__magenta(void *thisObj);
// QColor::magentaF() const
TestBindings_EXPORT float c_QColor__magentaF(void *thisObj);
// QColor::name() const
TestBindings_EXPORT void *c_QColor__name(void *thisObj);
// QColor::red() const
TestBindings_EXPORT int c_QColor__red(void *thisObj);
// QColor::redF() const
TestBindings_EXPORT float c_QColor__redF(void *thisObj);
// QColor::saturation() const
TestBindings_EXPORT int c_QColor__saturation(void *thisObj);
// QColor::saturationF() const
TestBindings_EXPORT float c_QColor__saturationF(void *thisObj);
// QColor::setAlpha(int alpha)
TestBindings_EXPORT void c_QColor__setAlpha_int(void *thisObj, int alpha);
// QColor::setAlphaF(float alpha)
TestBindings_EXPORT void c_QColor__setAlphaF_float(void *thisObj, float alpha);
// QColor::setBlue(int blue)
TestBindings_EXPORT void c_QColor__setBlue_int(void *thisObj, int blue);
// QColor::setBlueF(float blue)
TestBindings_EXPORT void c_QColor__setBlueF_float(void *thisObj, float blue);
// QColor::setCmyk(int c, int m, int y, int k, int a)
TestBindings_EXPORT void c_QColor__setCmyk_int_int_int_int_int(void *thisObj, int c, int m, int y,
                                                               int k, int a);
// QColor::setCmykF(float c, float m, float y, float k, float a)
TestBindings_EXPORT void c_QColor__setCmykF_float_float_float_float_float(void *thisObj, float c,
                                                                          float m, float y, float k,
                                                                          float a);
// QColor::setGreen(int green)
TestBindings_EXPORT void c_QColor__setGreen_int(void *thisObj, int green);
// QColor::setGreenF(float green)
TestBindings_EXPORT void c_QColor__setGreenF_float(void *thisObj, float green);
// QColor::setHsl(int h, int s, int l, int a)
TestBindings_EXPORT void c_QColor__setHsl_int_int_int_int(void *thisObj, int h, int s, int l,
                                                          int a);
// QColor::setHslF(float h, float s, float l, float a)
TestBindings_EXPORT void c_QColor__setHslF_float_float_float_float(void *thisObj, float h, float s,
                                                                   float l, float a);
// QColor::setHsv(int h, int s, int v, int a)
TestBindings_EXPORT void c_QColor__setHsv_int_int_int_int(void *thisObj, int h, int s, int v,
                                                          int a);
// QColor::setHsvF(float h, float s, float v, float a)
TestBindings_EXPORT void c_QColor__setHsvF_float_float_float_float(void *thisObj, float h, float s,
                                                                   float v, float a);
// QColor::setNamedColor(const QString & name)
TestBindings_EXPORT void c_QColor__setNamedColor_QString(void *thisObj, const char *name_);
// QColor::setRed(int red)
TestBindings_EXPORT void c_QColor__setRed_int(void *thisObj, int red);
// QColor::setRedF(float red)
TestBindings_EXPORT void c_QColor__setRedF_float(void *thisObj, float red);
// QColor::setRgb(int r, int g, int b, int a)
TestBindings_EXPORT void c_QColor__setRgb_int_int_int_int(void *thisObj, int r, int g, int b,
                                                          int a);
// QColor::setRgbF(float r, float g, float b, float a)
TestBindings_EXPORT void c_QColor__setRgbF_float_float_float_float(void *thisObj, float r, float g,
                                                                   float b, float a);
// QColor::toCmyk() const
TestBindings_EXPORT void *c_QColor__toCmyk(void *thisObj);
// QColor::toExtendedRgb() const
TestBindings_EXPORT void *c_QColor__toExtendedRgb(void *thisObj);
// QColor::toHsl() const
TestBindings_EXPORT void *c_QColor__toHsl(void *thisObj);
// QColor::toHsv() const
TestBindings_EXPORT void *c_QColor__toHsv(void *thisObj);
// QColor::toRgb() const
TestBindings_EXPORT void *c_QColor__toRgb(void *thisObj);
// QColor::value() const
TestBindings_EXPORT int c_QColor__value(void *thisObj);
// QColor::valueF() const
TestBindings_EXPORT float c_QColor__valueF(void *thisObj);
// QColor::yellow() const
TestBindings_EXPORT int c_QColor__yellow(void *thisObj);
// QColor::yellowF() const
TestBindings_EXPORT float c_QColor__yellowF(void *thisObj);
TestBindings_EXPORT void c_QColor__destructor(void *thisObj);
TestBindings_EXPORT void c_QColor_Finalizer(void *cppObj);
}
