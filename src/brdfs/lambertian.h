#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include <brdf.h>

class Lambertian: public BRDF
{
public:
    Lambertian(float l_kd = 1.0, const Color &l_cd = Color(1));

    virtual Color f(const Intersection &is, const vec3 &wi, const vec3 &wo) const;
    virtual Color rho(const Intersection &is, const vec3 &wo) const;
    void setKd(float);
    void setCd(const Color &);


private:
    float kd;
    Color cd;
};

#endif
