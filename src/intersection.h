#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <mymath.h>
#include <ray.h>

class World;
class Material;

struct Intersection
{
    bool hit_an_object;
    FLOAT t; //object->hit(...)
    vec3 hit_point;//world->hitObjects()
    vec3 normal;//object->hit(...)
    const Material *material;//world->hitObjects()
    uint depth;//
    Ray ray;//
    vec3 dir;//
    const World &w;//world->hitObjects()

    Intersection(const World &l_w): hit_an_object(false), t(INFINITY),
      material(NULL), depth(0), w(l_w)
    {
    }

    Intersection(const Intersection &is): hit_an_object(is.hit_an_object),
      t(is.t), hit_point(is.hit_point), normal(is.normal),
      material(is.material), depth(is.depth), ray(is.ray), dir(is.dir), w(is.w)
    {

    }

    Intersection &operator =(const Intersection &is)
    {
        hit_an_object = is.hit_an_object;
        t = is.t;
        hit_point = is.hit_point;
        normal = is.normal;
        material = is.material;
        depth = is.depth;
        ray = is.ray;
        dir = is.dir;

        return *this;
    }

    operator bool() const
    {
        return hit_an_object;
    }

    bool operator <(const Intersection &is) const
    {
        return t < is.t;
    }
};

#endif
