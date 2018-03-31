#include <objects/triangle.h>
#include <intersection.h>
#include <glm/gtc/constants.hpp>
#include <material.h>

Triangle Triangle::prototype("Triangle");

Triangle::Triangle(const std::string &name): Object(name),
  v0(1, 0, 0), v1(0, 0, -1), v2(-1, 0, 0)
{
}

bool Triangle::hit(const Ray &ray, Intersection &is) const
{
    is.hit_an_object = false;

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

bool Triangle::shadowHit(const Ray &ray, FLOAT &tmin) const
{
    if (!shadows)
    {
        return false;
    }

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

BBox Triangle::getBBox() const
{
    FLOAT min_x = glm::min(v0.x, glm::min(v1.x, v2.x));
    FLOAT min_y = glm::min(v0.y, glm::min(v1.y, v2.y));
    FLOAT min_z = glm::min(v0.z, glm::min(v1.z, v2.z));

    FLOAT max_x = glm::max(v0.x, glm::max(v1.x, v2.x));
    FLOAT max_y = glm::max(v0.y, glm::max(v1.y, v2.y));
    FLOAT max_z = glm::max(v0.z, glm::max(v1.z, v2.z));

    return BBox(vec3(min_x, min_y, min_z) - vec3(EPSILON), vec3(max_x, max_y, max_z) + vec3(EPSILON));
}

void Triangle::deserialize(TiXmlElement *element)
{
    TiXmlAttribute *attr = element->FirstAttribute();

    while (attr)
    {
        std::string name(attr->Name());

        if (name == "v0")
        {
            parseVec3(attr, v0);
        }
        else if (name == "v1")
        {
            parseVec3(attr, v1);
        }
        else if (name == "v2")
        {
            parseVec3(attr, v2);
        }

        attr = attr->Next();
    }

    normal = glm::normalize(glm::cross(v1 - v0, v2 - v0));

    material = Material::create(element->FirstChildElement("material"));
}
