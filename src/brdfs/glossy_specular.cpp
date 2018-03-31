#include <brdfs/glossy_specular.h>
#include <intersection.h>
#include <samplers/multi_jittered.h>
#include <world.h>

GlossySpecular::GlossySpecular(float l_ks, float l_e, const Color &l_cr):
  ks(l_ks), e(l_e), cr(l_cr)
{
}

GlossySpecular::GlossySpecular(const GlossySpecular &o):
  ks(o.ks), e(o.e), cr(o.cr)
{
}

Color GlossySpecular::f(const Intersection &is, const vec3 &wi, const vec3 &wo) const
{
    FLOAT ndotwi = glm::dot(is.normal, wi);
    vec3 r = -wi + FLOAT(2) * is.normal * ndotwi;

    float rdotwo = glm::dot(r, wo);

    if (rdotwo > 0.0)
    {
        return ks * cr * float(glm::pow(rdotwo, e));
    }

    return Color(0);
}

void GlossySpecular::setKs(float l_ks)
{
    ks = l_ks;
}

void GlossySpecular::setE(float l_e)
{
    e = l_e;
}

void GlossySpecular::setCr(const Color &l_cr)
{
    cr = l_cr;
}

void GlossySpecular::setSampler()
{
    sampler.reset(new MultiJittered(World::getInstance().vp.num_samples));

    sampler->mapToHemisphere(e);
}

Color GlossySpecular::sample_f(const Intersection &is, vec3 &wi, const vec3 &wo, float &pdf) const
{
    vec3 up(0.00424, 1, 0.00764);

    FLOAT ndotwo = glm::dot(is.normal, wo);

    vec3 w = -wo + 2.0 * is.normal * ndotwo;
    vec3 v = glm::normalize(glm::cross(w, up));
    vec3 u = glm::cross(v, w);

    vec3 sp = sampler->sampleHemisphere();

    wi = sp.x * u + sp.y * v + sp.z * w;

    if (glm::dot(wi, is.normal) < 0)
    {
        wi = -sp.x * u - sp.y * v + sp.z * w;
    }

    float ndotwi = glm::dot(is.normal, wi);

    float phong_lobe = glm::pow(glm::dot(w, wi), e);
    pdf = phong_lobe * ndotwi;

    return ks * cr * phong_lobe;
}
