#include <brdfs/lambertian.h>

Lambertian::Lambertian(float l_kd, const Color &l_cd): kd(l_kd), cd(l_cd)
{
}

Color Lambertian::f(const Intersection &is, const vec3 &wi, const vec3 &wo) const
{
    return kd * glm::one_over_pi<float>() * cd;
}

Color Lambertian::rho(const Intersection &is, const vec3 &wo) const
{
    return kd * cd;
}

void Lambertian::setKd(float k)
{
    kd = k;
}

void Lambertian::setCd(const Color &c)
{
    cd = c;
}
