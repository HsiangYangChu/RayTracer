#include <lights/ambient.h>

Ambient Ambient::prototype("Ambient");

Ambient::Ambient(const std::string &name): Light(name), ls(1.0), color(1)
{
}

Ambient::Ambient():
  ls(1.0), color(1)
{
}

vec3 Ambient::getDirection(const Intersection &) const
{
    return vec3(0);
}

Color Ambient::getL(const Intersection &is) const
{
    return ls * color;
}

void Ambient::deserialize(TiXmlElement *element)
{
    TiXmlAttribute *attr = element->FirstAttribute();

    while (attr)
    {
        std::string name(attr->Name());

        if (name == "ls")
        {
            parseFloat(attr, ls);
        }
        else if (name == "color")
        {
            parseColor(attr, color);
        }

        attr = attr->Next();
    }
}
