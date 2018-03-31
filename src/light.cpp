#include <lights/lights.h>

Light::Prototypes &Light::getPrototypes()
{
    static Prototypes prototypes;

    return prototypes;
}


Light::Light_ptr Light::create(TiXmlElement *element)
{
    if (!element)
    {
        return Light_ptr();
    }

    Prototypes &prototypes = getPrototypes();

    std::string name(element->Value());
    auto it = prototypes.find(name);

    if (it == prototypes.end())
    {
        return Light_ptr();
    }

    Light_ptr light = Light_ptr(it->second->clone());

    if (light)
    {
        light->deserialize(element);
    }

    return light;
}
