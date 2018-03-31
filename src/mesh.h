#ifndef MESH_H
#define MESH_H

#include <mymath.h>

#include <vector>

struct Mesh
{
    typedef std::vector<vec3> Verticles;
    typedef std::vector<uint> Indices;
    typedef std::vector<Indices> Faces;
    typedef std::vector<vec3> Normals;
    typedef std::vector<float> U_Coords;
    typedef std::vector<float> V_Coords;

    Verticles vertices;
    Faces vertex_faces;
    Normals normals;
    Indices indices;
    U_Coords u;
    V_Coords v;

    uint num_vertices;
    uint num_triangles;
};

#endif
