#ifndef TRIANGLE_MESH_H
#define TRIANGLE_MESH_H

#include <objects/grid.h>
#include <mesh.h>

typedef enum
{
    FLAT_TRIANGLE,
    SMOOTH_TRIANGLE
} TriangleType;

class TriangleMesh: public Grid
{
public:
    typedef std::shared_ptr<Mesh> Mesh_ptr;

    TriangleMesh(const std::string &name);
    ~TriangleMesh() {}

    void loadFromPlyFile(const char *, TriangleType, bool reverse_normals = false);
    virtual void deserialize(TiXmlElement *);
    virtual Object *clone() const
    {
        return new TriangleMesh(*this);
    }

private:
    static TriangleMesh prototype;

    Mesh_ptr mesh;

    void setupVertexNormals();
};

#endif // TRIANGLE_MESH_H
