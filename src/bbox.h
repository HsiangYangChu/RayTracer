#ifndef BBOX_H
#define BBOX_H

#include <mymath.h>
#include <ray.h>

struct BBox
{
    BBox(const vec3 &l_p0 = vec3(-1, -1, -1), const vec3 &l_p1 = vec3(1, 1, 1));

    bool hit(const Ray &) const;
    bool hit(const Ray &, FLOAT &, vec3 &, vec3 &) const;
    bool isInside(const vec3 &) const;

    vec3 p0;
    vec3 p1;
};

#endif
