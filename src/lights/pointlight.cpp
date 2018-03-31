#include <lights/pointlight.h>
#include <intersection.h>
#include <world.h>
#include <object.h>

PointLight PointLight::prototype("PointLight");

PointLight::PointLight(const std::string &name): Light(name),
  ls(1), location(0), color(1)
{
}

PointLight::PointLight(): Light(),
  ls(1), location(0), color(1)
{
}

vec3 PointLight::getDirection(const Intersection &is) const
{
    return glm::normalize(location - is.hit_point);
}

Color PointLight::getL(const Intersection &is) const
{
    return ls * color;
}

bool PointLight::inShadow(const Ray &ray, const Intersection &is) const
{
    if (!shadows)
    {
        return false;
    }

    const World::Objects &objects = is.w.objects;
    FLOAT t;

    for (uint i = 0; i < objects.size(); i++)
    {
        FLOAT distance = glm::distance(ray.o, location);
        if (objects[i]->shadowHit(ray, t) && t < distance)
        {
            return true;
        }
    }

    return false;
}

void PointLight::deserialize(TiXmlElement *element)
{
    TiXmlAttribute *attr = element->FirstAttribute();

    while (attr)
    {
        std::string name(attr->Name());

        if (name == "ls")
        {
            parseFloat(attr, ls);
        }
        else if (name == "location")
        {
            parseVec3(attr, location);
        }
        else if (name == "color")
        {
            parseColor(attr, color);
        }

        attr = attr->Next();
    }
}
