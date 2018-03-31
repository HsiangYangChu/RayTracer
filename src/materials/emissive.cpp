#include <materials/emissive.h>
#include <intersection.h>
#include <texture.h>

Emissive Emissive::prototype("Emissive");

Emissive::Emissive(const std::string &name): Material(name),
  ls(1.0), ce(1)
{
}

Emissive::Emissive():
  ls(1.0), ce(1)
{
}

Color Emissive::shade(const Intersection &is) const
{
    return areaLightShade(is);
}

Color Emissive::areaLightShade(const Intersection &is) const
{
    if (glm::dot(is.normal, is.ray.d) < 0)
    {
        return Texture::maxToOne(ls * ce);
    }

    return Color(0);
}

Color Emissive::getLe(const Intersection &is) const
{
    return ls * ce;
}

void Emissive::deserialize(TiXmlElement *element)
{

    TiXmlAttribute *attr = element->FirstAttribute();

    while (attr)
    {
        std::string name(attr->Name());

        if (name == "ls")
        {
            parseFloat(attr, ls);
        }
        else if (name == "ce")
        {
            parseColor(attr, ce);
        }

        attr = attr->Next();
    }
}
