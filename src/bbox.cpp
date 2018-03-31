#include <bbox.h>

BBox::BBox(const vec3 &l_p0, const vec3 &l_p1):
  p0(l_p0), p1(l_p1)
{
}

bool BBox::hit(const Ray &ray) const
{
    FLOAT t0;
    vec3 tmin, tmax;

    return hit(ray, t0, tmin, tmax);
}

bool BBox::hit(const Ray &ray, FLOAT &t_in, vec3 &tmin, vec3 &tmax) const
{
    FLOAT t_out;

    vec3 inv_d = vec3(1) / ray.d;

    for (uint i = 0; i < 3; i++)
    {
        if (ray.d[i] >= 0)
        {
            tmin[i] = (p0[i] - ray.o[i]) * inv_d[i];
            tmax[i] = (p1[i] - ray.o[i]) * inv_d[i];
        }
        else
        {
            tmin[i] = (p1[i] - ray.o[i]) * inv_d[i];
            tmax[i] = (p0[i] - ray.o[i]) * inv_d[i];
        }
    }

    t_in = glm::compMax(tmin);
    t_out = glm::compMin(tmax);

    return (t_in < t_out && t_out > EPSILON);
}

bool BBox::isInside(const vec3 &v) const
{
    auto b1 = glm::lessThan(p0, v);
    auto b2 = glm::lessThan(v, p1);

    return glm::all(b1) && glm::all(b2);
}

