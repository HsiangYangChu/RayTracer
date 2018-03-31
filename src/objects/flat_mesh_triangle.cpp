#include <objects/flat_mesh_triangle.h>
#include <intersection.h>
#include <mesh.h>

FlatMeshTriangle::FlatMeshTriangle(uint i0, uint i1, uint i2, const Mesh *m):
  MeshTriangle(i0, i1, i2, m)
{
}

bool FlatMeshTriangle::hit(const Ray &ray, Intersection &is) const
{
    is.hit_an_object = false;

    const vec3 &v0 = mesh->vertices[index0];
    const vec3 &v1 = mesh->vertices[index1];
    const vec3 &v2 = mesh->vertices[index2];

    vec3 ba = v0 - v1;
    vec3 ca = v0 - v2;
    vec3 rd = ray.d;
    vec3 oa = v0 - ray.o;

    FLOAT a = ba.x;
    FLOAT b = ca.x;
    FLOAT c = rd.x;
    FLOAT d = oa.x;
    FLOAT e = ba.y;
    FLOAT f = ca.y;
    FLOAT g = rd.y;
    FLOAT h = oa.y;
    FLOAT i = ba.z;
    FLOAT j = ca.z;
    FLOAT k = rd.z;
    FLOAT l = oa.z;

    FLOAT invDet = 1 / (a * (f * k - j * g) - b * (e * k - i * g) + c * (e * j - i * f));

    FLOAT beta = (d * (f * k - j * g) - b * (h * k - l * g) + c * (h * j - l * f)) * invDet;

    if (beta < 0 || beta > 1)
    {
        return false;
    }

    FLOAT gamma = (a * (h * k - l * g) - d * (e * k - i * g) + c * (e * l - i * h)) * invDet;

    if (gamma < 0 || (beta + gamma) > 1)
    {
        return false;
    }

    FLOAT t = (a * (f * l - j * h) - b * (e * l - i * h) + d * (e * j - i * f)) * invDet;

    if (t < EPSILON)
    {
        return false;
    }

    is.t = t;
    is.normal = normal;
    is.hit_an_object = true;

    return true;
}
