#include <datastore.h>
#include <vector>
#include <object.h>
#include <material.h>

DataStore::DataStore()
{
}

DataStore &DataStore::getInstance()
{
    static DataStore datastore;

    return datastore;
}

void DataStore::init(TiXmlElement *scene)
{
    objects.clear();
    materials.clear();

    TiXmlElement *data = scene->FirstChildElement("data");

    if (!data)
    {
        return;
    }

    std::vector<Pair> obj_headers, mat_headers;

    TiXmlElement *header = data->FirstChildElement();

    while (header)
    {
        TiXmlElement *element = header->FirstChildElement();

        if (element)
        {
            Pair pair;

            pair.name = header->Value();
            pair.element = element;

            std::string type(header->Attribute("type"));

            if (type == "object")
            {
                obj_headers.push_back(pair);
            }
            else if (type == "material")
            {
                mat_headers.push_back(pair);
            }
        }

        header = header->NextSiblingElement();
    }


    for (uint i = 0; i < mat_headers.size(); i++)
    {
        Material_ptr material = Material::create(mat_headers[i].element);

        if (material)
        {
            materials.insert(std::make_pair(mat_headers[i].name, material));
        }
    }

    for (uint i = 0; i < obj_headers.size(); i++)
    {
        Object_ptr object = Object::create(obj_headers[i].element);

        if (object)
        {
            objects.insert(std::make_pair(obj_headers[i].name, object));
        }
    }
}

DataStore::Object_ptr DataStore::getObject(const std::string &name)
{
    auto it = objects.find(name);

    if (it == objects.end())
    {
        return Object_ptr();
    }

    return it->second;
}

DataStore::Material_ptr DataStore::getMaterial(const std::string &name)
{
    auto it = materials.find(name);

    if (it == materials.end())
    {
        return Material_ptr();
    }

    return it->second;
}

void DataStore::clear()
{
    objects.clear();
    materials.clear();
}
