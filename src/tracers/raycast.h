#ifndef MULTIPLE_OBJECTS_H
#define MULTIPLE_OBJECTS_H

#include <tracer.h>
#include <iostream>

class RayCast: public Tracer
{
public:

    RayCast(const std::string &);
    RayCast();
    ~RayCast() {}

    virtual Tracer *clone() const;
    virtual Color traceRay(const Ray &ray, uint depth = 0) const;

private:
    static RayCast prototype;
};

#endif
