#include <mymath.h>

const FLOAT invRAND_MAX = 1.0 / RAND_MAX;

FLOAT rand_float()
{
    return rand() * invRAND_MAX;
}

FLOAT rand_float(FLOAT a, FLOAT b)
{
    return a + rand_float() * (b - a);
}

int rand_int()
{
    return rand();
}

int rand_int(int a, int b)
{
    return a + rand_float() * (b - a + 1);
}

vec3 transform_vector(const mat4 &mat, const vec3 &vec)
{
    vec4 v(vec, 0);

    return vec3( mat * v );
}

vec3 transform_point(const mat4 &mat, const vec3 &vec)
{
    vec4 v(vec, 1);

    return vec3( mat * v );
}

vec3 transform_normal(const mat4 &local, const vec3 &vec)
{
    return transform_vector(glm::transpose(local), vec);
}
