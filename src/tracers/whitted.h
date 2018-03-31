#ifndef WHITTED_H
#define WHITTED_H

#include <tracer.h>

class Whitted: public Tracer
{
public:

    Whitted(const std::string &);
    ~Whitted() {}

    virtual Tracer *clone() const;
    virtual Color traceRay(const Ray &ray, uint depth) const;

private:
    static Whitted prototype;
};

#endif
