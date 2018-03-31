#ifndef DATASTORE_H
#define DATASTORE_H

#include <memory>
#include <string>
#include <map>
#include <tinyxml/tinyxml.h>

class Object;
class Material;

class DataStore
{
public:
    typedef std::shared_ptr<Object> Object_ptr;
    typedef std::shared_ptr<Material> Material_ptr;
    typedef std::map<std::string, Object_ptr> Objects;
    typedef std::map<std::string, Material_ptr> Materials;

    static DataStore &getInstance();

    void init(TiXmlElement *);
    void clear();
    Object_ptr getObject(const std::string &);
    Material_ptr getMaterial(const std::string &);

private:

    struct Pair
    {
        std::string name;
        TiXmlElement *element;

        Pair(): element(NULL)
        {
        }
    };

    DataStore();

    Objects objects;
    Materials materials;
};

#endif
