#include <objects/objects.h>
#include <material.h>
#include <datastore.h>

Object::Object(const std::string &name): shadows(true)
{
    Prototypes &prototypes = getPrototypes();

    prototypes.insert(std::make_pair(name, this));
}

Object::Object(): shadows(true)
{
}

Object::Object(const Object &): shadows(true)
{
}

Object::Prototypes &Object::getPrototypes()
{
    static Object::Prototypes prototypes;

    return prototypes;
}

void Object::setShadows(bool l_shadows)
{
    shadows = l_shadows;
}

Object::Material_ptr Object::getMaterial() const
{
    return material;
}

void Object::setMaterial(const Material_ptr &ptr)
{
    material = ptr;
}

void Object::sample(vec3 &point, vec3 &normal) const
{
    point = vec3(0, 0, 0);
    normal = vec3(0, 1, 0);
}

float Object::pdf(const Intersection &is) const
{
    return 1;
}

BBox Object::getBBox() const
{
    return BBox();
}

vec3 Object::getNormal() const
{
    return vec3(0, 1, 0);
}

void Object::setSampler(Sampler *)
{
}

Object::Object_ptr Object::create(TiXmlElement *element)
{
    if (!element)
    {
        return Object_ptr();
    }

    std::string name(element->Value());

    if (name == "object")
    {
        TiXmlElement *content = element->FirstChildElement();

        if (!content)
        {
            const char *text = element->GetText();

            if (text)
            {
                return DataStore::getInstance().getObject(text);
            }

            return Object_ptr();
        }

        return create(content);
    }

    Prototypes &prototypes = getPrototypes();

    auto it = prototypes.find(name);

    if (it == prototypes.end())
    {
        return Object_ptr();
    }

    Object_ptr object(it->second->clone());

    if (object)
    {
        object->deserialize(element);
    }

    return object;
}
