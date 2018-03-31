#ifndef AMBIENT_OCCLUDER_H
#define AMBIENT_OCCLUDER_H

#include <light.h>
#include <memory>

class Sampler;

class AmbientOccluder: public Light
{
public:
    typedef std::unique_ptr<Sampler> Sampler_ptr;

    AmbientOccluder(const std::string &);
    AmbientOccluder(const AmbientOccluder &);
    ~AmbientOccluder();

    virtual vec3 getDirection(const Intersection &) const;
    virtual Color getL(const Intersection &) const;
    virtual bool inShadow(const Ray &, const Intersection &) const;
    virtual void deserialize(TiXmlElement *);

    virtual Light *clone() const
    {
        return new AmbientOccluder(*this);
    }

    void setSampler(Sampler *);

private:
    static AmbientOccluder prototype;

    Sampler_ptr sampler;
    float min_light;
    float ls;
    Color color;
};

#endif
