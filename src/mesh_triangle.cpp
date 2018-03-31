#include <mesh_triangle.h>
#include <ray.h>
#include <mesh.h>

MeshTriangle::MeshTriangle(uint i0, uint i1, uint i2, const Mesh *m):
  index0(i0), index1(i1), index2(i2), mesh(m)
{
}

bool MeshTriangle::shadowHit(const Ray &ray, FLOAT &tmin) const
{
    if (!shadows)
    {
        return false;
    }

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

    if (t < BIAS)
    {
        return false;
    }

    tmin = t;

    return true;
}

float MeshTriangle::interpolateU(float beta, float gamma) const
{
    return (1 - beta - gamma) * mesh->u[index0] +
           beta * mesh->u[index1] + gamma * mesh->u[index2];
}

float MeshTriangle::interpolateV(float beta, float gamma) const
{
    return (1 - beta - gamma) * mesh->v[index0] +
           beta * mesh->v[index1] + gamma * mesh->v[index2];
}

BBox MeshTriangle::getBBox() const
{
    const vec3 &v0 = mesh->vertices[index0];
    const vec3 &v1 = mesh->vertices[index1];
    const vec3 &v2 = mesh->vertices[index2];

    FLOAT min_x = glm::min(v0.x, glm::min(v1.x, v2.x));
    FLOAT min_y = glm::min(v0.y, glm::min(v1.y, v2.y));
    FLOAT min_z = glm::min(v0.z, glm::min(v1.z, v2.z));

    FLOAT max_x = glm::max(v0.x, glm::max(v1.x, v2.x));
    FLOAT max_y = glm::max(v0.y, glm::max(v1.y, v2.y));
    FLOAT max_z = glm::max(v0.z, glm::max(v1.z, v2.z));

    return BBox(vec3(min_x, min_y, min_z) - vec3(EPSILON),
                vec3(max_x, max_y, max_z) + vec3(EPSILON));
}

void MeshTriangle::computeNormal(bool reverse_normal)
{
    const vec3 &v0 = mesh->vertices[index0];
    const vec3 &v1 = mesh->vertices[index1];
    const vec3 &v2 = mesh->vertices[index2];

    normal = glm::normalize(glm::cross(v1 - v0, v2 - v0));

    if (reverse_normal)
    {
        normal = -normal;
    }
}

vec3 MeshTriangle::getNormal() const
{
    return normal;
}
