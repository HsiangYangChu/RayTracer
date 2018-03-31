#ifndef MESH_TRIANGLE_H
#define MESH_TRIANGLE_H

#include <object.h>

class Mesh;

class MeshTriangle: public Object
{
public:
    MeshTriangle(uint, uint, uint, const Mesh *);
    ~MeshTriangle() {}

    virtual bool shadowHit(const Ray &, FLOAT &) const;
    virtual BBox getBBox() const;
    virtual vec3 getNormal() const;
    void computeNormal(bool);

    float interpolateU(float, float) const;
    float interpolateV(float, float) const;

protected:
    uint index0;
    uint index1;
    uint index2;

    vec3 normal;

    const Mesh *mesh;

    BBox bbox;
};

#endif
