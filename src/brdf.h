#ifndef BRDF_H
#define BRDF_H

#include <mymath.h>
#include <sampler.h>
#include <memory>

class Sampler;
struct Intersection;

class BRDF
{
public:
    typedef std::unique_ptr<Sampler> Sampler_ptr;

    BRDF()
    {
    }

    BRDF(const BRDF &)
    {
    }

    virtual Color f(const Intersection &is, const vec3 &wi, const vec3 &wo) const
    {
        return Color(0);
    }

    virtual Color sample_f(const Intersection &is, vec3 &wi, const vec3 &wo) const
    {
        return Color(0);
    }

    virtual Color rho(const Intersection &is, const vec3 &wo) const
    {
        return Color(0);
    }

protected:
    Sampler_ptr sampler;
};

#endif
