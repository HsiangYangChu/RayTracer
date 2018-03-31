#ifndef SMOOTH_MESH_TRIANGLE_H
#define SMOOTH_MESH_TRIANGLE_H

#include <mesh_triangle.h>

class SmoothMeshTriangle: public MeshTriangle
{
public:
    SmoothMeshTriangle(uint, uint, uint, const Mesh *);
    ~SmoothMeshTriangle() {}
    virtual bool hit(const Ray &, Intersection &) const;
    vec3 interpolateNormal(FLOAT, FLOAT) const;
    virtual void deserialize(TiXmlElement *)
    {
    }
};

#endif
