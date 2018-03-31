#include <lights/directional.h>
#include <world.h>
#include <object.h>

Directional Directional::prototype("Directional");

Directional::Directional(const std::string &name): Light(name),
  ls(1), dir(0, 1, 0), color(1)
{
}

vec3 Directional::getDirection(const Intersection &is) const
{
    return dir;
}

Color Directional::getL(const Intersection &is) const
{
    return ls * color;
}

bool Directional::inShadow(const Ray &ray, const Intersection &is) const
{
    if (!shadows)
    {
        return false;
    }

    const World::Objects &objects = is.w.objects;
    FLOAT t;

    for (uint i = 0; i < objects.size(); i++)
    {
        if (objects[i]->shadowHit(ray, t))
        {
            return true;
        }
    }

    return false;
}

void Directional::deserialize(TiXmlElement *element)
{
    TiXmlAttribute *attr = element->FirstAttribute();

    while (attr)
    {
        std::string name(attr->Name());

        if (name == "ls")
        {
            parseFloat(attr, ls);
        }
        else if (name == "dir")
        {
            parseVec3(attr, dir);
        }
        else if (name == "color")
        {
            parseColor(attr, color);
        }

        attr = attr->Next();
    }
}
