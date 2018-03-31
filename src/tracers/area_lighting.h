#ifndef AREA_LIGHTING_H
#define AREA_LIGHTING_H

#include <tracer.h>

class AreaLighting: public Tracer
{
public:

    AreaLighting(const std::string &);
    ~AreaLighting() {}

    virtual Tracer *clone() const;
    virtual Color traceRay(const Ray &ray, uint depth) const;

private:
    static AreaLighting prototype;
};

#endif
