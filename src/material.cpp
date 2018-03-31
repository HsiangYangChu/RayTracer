#include <material.h>
#include <datastore.h>

Material::Material(const std::string &name)
{
    getPrototypes().insert(std::make_pair(name, this));
}

Material::Material()
{
}

Material::Prototypes &Material::getPrototypes()
{
    static Prototypes prototypes;

    return prototypes;
}

Material::Material_ptr Material::create(TiXmlElement *element)
{
    if (!element)
    {
        return Material_ptr();
    }

    std::string name(element->Value());

    if (name == "material")
    {
        TiXmlElement *content = element->FirstChildElement();

        if (!content)
        {
            const char *text = element->GetText();

            if (text)
            {
                return DataStore::getInstance().getMaterial(text);
            }

            return Material_ptr();
        }

        return create(content);
    }

    Prototypes &prototypes = getPrototypes();

    auto it = prototypes.find(name);

    if (it == prototypes.end())
    {
        return Material_ptr();
    }

    Material_ptr material(it->second->clone());

    if (material)
    {
        material->deserialize(element);
    }

    return material;
}
