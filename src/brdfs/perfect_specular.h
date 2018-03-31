#ifndef PERFECT_SPECULAR_H
#define PERFECT_SPECULAR_H

#include <brdf.h>

class PerfectSpecular: public BRDF
{
public:
    PerfectSpecular(float l_kr = 0.4, Color l_cr = Color(1));
    virtual Color sample_f(const Intersection &is, vec3 &wi, const vec3 &wo) const;

    void setKr(float);
    void setCr(const Color &);

private:
    float kr;
    Color cr;
};

#endif
