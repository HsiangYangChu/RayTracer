#include <objects/sphere.h>
#include <ray.h>
#include <intersection.h>
#include <material.h>

Sphere Sphere::prototype("Sphere");

Sphere::Sphere(const std::string &name): Object(name),
  center(0), r(1)
{
}

bool Sphere::hit(const Ray &ray, Intersection &is) const
{
    is.hit_an_object = false;

    double a = glm::length2(ray.d);
    double b = 2 * glm::dot(ray.o - center, ray.d);
    double c = glm::length2(ray.o - center) - r * r;

    double D = b * b - 4 * a * c;

    if (D >= 0)
    {
        double t1 = (-b - glm::sqrt(D)) / (2 * a);
        double t2 = (-b + glm::sqrt(D)) / (2 * a);

        if (t2 > EPSILON)
        {
            if (t1 <= EPSILON)
            {
                is.t = t2;
            }
            else
            {
                is.t = t1;
            }

            is.hit_point = ray.o + is.t * ray.d;
            is.normal = (is.hit_point - center) / r;

            return true;
        }

        return false;
    }

    return false;
}

void Sphere::setCenter(const vec3 &l_center)
{
    center = l_center;
}

void Sphere::setRadius(FLOAT l_r)
{
    r = l_r;
}

bool Sphere::shadowHit(const Ray &ray, FLOAT &tmin) const
{
    if (!shadows)
    {
        return false;
    }

    double a = glm::length2(ray.d);
    double b = 2 * glm::dot(ray.o - center, ray.d);
    double c = glm::length2(ray.o - center) - r * r;

    double D = b * b - 4 * a * c;

    if (D >= 0)
    {
        double t1 = (-b - glm::sqrt(D)) / (2 * a);
        double t2 = (-b + glm::sqrt(D)) / (2 * a);

        if (t2 > BIAS)
        {
            if (t1 <= BIAS)
            {
                tmin = t2;
            }
            else
            {
                tmin = t1;
            }

            return true;
        }

        return false;
    }

    return false;
}

BBox Sphere::getBBox() const
{
    return BBox(center - vec3(r + EPSILON), center + vec3(r + EPSILON));
}

void Sphere::deserialize(TiXmlElement *element)
{
    TiXmlAttribute *attr = element->FirstAttribute();

    while (attr)
    {
        std::string name(attr->Name());

        if (name == "center")
        {
            parseVec3(attr, center);
        }
        else if (name == "r")
        {
            parseDouble(attr, r);
        }

        attr = attr->Next();
    }

    material = Material::create(element->FirstChildElement("material"));
}
