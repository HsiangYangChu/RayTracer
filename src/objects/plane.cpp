#include <objects/plane.h>
#include <ray.h>
#include <intersection.h>
#include <material.h>

Plane Plane::prototype("Plane");

Plane::Plane(const std::string &name): Object(name),
  point(0), normal(0, 1, 0)
{
}

Plane::Plane(const Plane &o): Object(o),
  point(o.point), normal(o.normal)
{
}

bool Plane::hit(const Ray &ray, Intersection &is) const
{
    is.hit_an_object = false;

    double a = glm::dot(point - ray.o, normal);
    double b = glm::dot(ray.d, normal);

    if (glm::abs(b) <= EPSILON)
    {
        return false;
    }

    is.t = a / b;

    if (is.t > EPSILON)
    {
        is.normal = normal;

        return true;
    }

    return false;
}

bool Plane::shadowHit(const Ray &ray, FLOAT &tmin) const
{
    if (!shadows)
    {
        return false;
    }

    double t = glm::dot(point - ray.o, normal) / glm::dot(ray.d, normal);

    if (t > BIAS)
    {
        tmin = t;
        return true;
    }

    return false;
}

BBox Plane::getBBox() const
{
    FLOAT d = INFINITY;

    return BBox(vec3(-d, -d, -d), vec3(d, d, d));
}

void Plane::deserialize(TiXmlElement *element)
{
    TiXmlAttribute *attr = element->FirstAttribute();

    while (attr)
    {
        std::string name(attr->Name());

        if (name == "point")
        {
            parseVec3(attr, point);
        }
        else if (name == "normal")
        {
            parseVec3(attr, normal);
            normal = glm::normalize(normal);
        }

        attr = attr->Next();
    }

    material = Material::create(element->FirstChildElement("material"));
}
