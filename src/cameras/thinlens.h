#ifndef THINLENS_H
#define THINLENS_H

#include <camera.h>
#include <sampler.h>
#include <memory>

struct ThinLens: public Camera
{
    typedef std::unique_ptr<Sampler> Sampler_ptr;

    ThinLens(const std::string &);
    ThinLens(const ThinLens &);
    ~ThinLens() {}

    vec3 lensRayDirection(const vec2&, const vec2&) const;
    void setSampler(Sampler *);
    virtual void build();
    virtual Color renderPixel(uint, uint) const;
    virtual void deserialize(TiXmlElement *);
    virtual Camera *clone() const;

    FLOAT f;
    FLOAT lens_radius;
    Sampler_ptr sampler;

private:
    static ThinLens prototype;
};

#endif
