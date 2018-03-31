#include <objects/disk.h>
#include <intersection.h>
#include <material.h>
#include <sampler.h>

Disk Disk::prototype("Disk");

Disk::Disk(const std::string &name): Plane(name),
  min_r(0), max_r(1), inv_area(1.f / M_PI)
{
}

Disk::Disk(const Disk &o): Plane(o),
  min_r(o.min_r), max_r(o.max_r), inv_area(o.inv_area)
{
}

Disk::~Disk() {}

void Disk::setSampler(Sampler *l_sampler)
{
    sampler.reset(l_sampler);
    sampler->mapToUnitDisk();
}

bool Disk::hit(const Ray &ray, Intersection &is) const
{
    is.hit_an_object = false;

    if (Plane::hit(ray, is))
    {
        FLOAT dist = glm::distance(ray.d * is.t + ray.o, point);
        is.hit_an_object = (dist >= min_r && dist <= max_r);

        return is.hit_an_object;
    }

    return false;
}

bool Disk::shadowHit(const Ray &ray, FLOAT &tmin) const
{
    if (Plane::shadowHit(ray, tmin))
    {
        FLOAT dist = glm::distance(ray.d * tmin + ray.o, point);

        return (dist >= min_r && dist <= max_r);
    }

    return false;
}

float Disk::pdf(const Intersection &is) const
{
    return inv_area;
}

void Disk::sample(vec3 &point, vec3 &l_normal) const
{
    vec2 sp(sampler->sampleUnitDisk());

    if (!(sp.x || sp.y))
    {
        sp.x = 1;
        sp.y = 0;
    }

    vec2 unit(glm::normalize(sp));
    vec2 p = min_r * unit + sp * (max_r - min_r);

    point = Plane::point + u * p.x + v * p.y;
    l_normal = normal;
}

BBox Disk::getBBox() const
{
    return BBox(Plane::point - vec3(max_r + EPSILON), Plane::point + vec3(max_r + EPSILON));
}

void Disk::deserialize(TiXmlElement *element)
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
        else if (name == "min_r")
        {
            parseDouble(attr, min_r);
        }
        else if (name == "max_r")
        {
            parseDouble(attr, max_r);
        }

        attr = attr->Next();
    }

    vec3 up = vec3(0.0072, 1.0, 0.0034);

    w = normal;
    v = glm::normalize(glm::cross(w, up));
    u = glm::cross(v, w);

    inv_area = 1.f / (M_PI * (max_r - min_r) * (max_r + min_r));

    material = Material::create(element->FirstChildElement("material"));
}
