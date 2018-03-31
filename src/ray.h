#ifndef RAY_H
#define RAY_H

#include <mymath.h>

struct Ray
{
    vec3 o;
    vec3 d;

    Ray(const vec3 &l_o = vec3(0), const vec3 &l_d = vec3(0, 0, -1)): o(l_o), d(l_d)
    {
    }

    void transform(const mat4 &mat)
    {
        o = transform_point(mat, o);
        d = transform_vector(mat, d);
    }
};

#endif
