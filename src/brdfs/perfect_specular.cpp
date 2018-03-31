#include <brdfs/perfect_specular.h>
#include <intersection.h>

PerfectSpecular::PerfectSpecular(float l_kr, Color l_cr): kr(l_kr), cr(l_cr)
{
}

Color PerfectSpecular::sample_f(const Intersection &is, vec3 &wi, const vec3 &wo) const
{
    FLOAT ndotwo = glm::dot(is.normal, wo);
    wi = -wo + 2 * ndotwo * is.normal;
    FLOAT inv_ndotwi = 1.0 / (glm::dot(is.normal, wi));

    return kr * cr * float(inv_ndotwi);
}

void PerfectSpecular::setKr(float l_kr)
{
    kr = l_kr;
}

void PerfectSpecular::setCr(const Color &l_cr)
{
    cr = l_cr;
}
