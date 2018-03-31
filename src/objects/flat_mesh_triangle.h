#ifndef FLAT_MESH_TRIANGLE_H
#define FLAT_MESH_TRIANGLE_H

#include <mesh_triangle.h>

class FlatMeshTriangle: public MeshTriangle
{
public:
    FlatMeshTriangle(uint, uint, uint, const Mesh *);
    ~FlatMeshTriangle() {}
    virtual bool hit(const Ray &, Intersection &) const;
    virtual void deserialize(TiXmlElement *)
    {
    }
};

#endif // FLAT_MESH_TRIANGLE_H
