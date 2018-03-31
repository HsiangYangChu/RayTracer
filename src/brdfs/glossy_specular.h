#ifndef GLOSSY_SPECULAR_H
#define GLOSSY_SPECULAR_H

#include <brdf.h>
#include <memory>

class Sampler;

class GlossySpecular: public BRDF
{
public:
    typedef std::unique_ptr<Sampler> Sampler_ptr;

    GlossySpecular(float l_ks = 0.1, float l_e = 10.0, const Color &l_cr = Color(1));
    GlossySpecular(const GlossySpecular &);

    virtual Color f(const Intersection &, const vec3 &, const vec3 &) const;
    virtual Color sample_f(const Intersection &, vec3 &, const vec3 &, float &) const;

    void setSampler();
    void setKs(float);
    void setE(float);
    void setCr(const Color &);

private:
    float ks;
    float e;
    Color cr;
    Sampler_ptr sampler;
};

#endif
