#ifndef MYMATH_H
#define MYMATH_H

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtx/norm.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/component_wise.hpp>
#include <cstdlib>

typedef double FLOAT;
typedef glm::dvec3 vec3;
typedef glm::dvec4 vec4;
typedef glm::dvec2 vec2;
typedef glm::dmat4 mat4;

typedef glm::vec3 Color;
typedef glm::uvec3 RGBColor;

typedef glm::dvec3 dvec3;
typedef glm::dvec4 dvec4;
typedef glm::dvec2 dvec2;
typedef glm::dmat4 dmat4;

typedef glm::vec3 fvec3;
typedef glm::vec4 fvec4;
typedef glm::vec2 fvec2;
typedef glm::mat4 fmat4;


#define EPSILON 1e-6
#define BIAS 1e-3

//const FLOAT invRAND_MAX = 1.0 / RAND_MAX;

FLOAT rand_float();
FLOAT rand_float(FLOAT, FLOAT);
int rand_int();
int rand_int(int, int);
vec3 transform_vector(const mat4 &, const vec3 &);
vec3 transform_point(const mat4 &, const vec3 &);
vec3 transform_normal(const mat4 &, const vec3 &);

#endif
