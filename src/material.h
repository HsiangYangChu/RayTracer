#ifndef MATERIAL_H
#define MATERIAL_H

#include <memory>
#include <serializable.h>
#include <map>

class Intersection;

class Material: public Serializable
{
public:
    typedef std::shared_ptr<Material> Material_ptr;
    typedef std::map<std::string, Material *> Prototypes;

    Material(const std::string &);
    Material();

    ~Material() {}

    virtual Color shade(const Intersection &) const
    {
        return Color(0);
    }

    virtual Color areaLightShade(const Intersection &) const
    {
        return Color(0);
    }

    virtual Color getLe(const Intersection &) const
    {
        return Color(0);
    }

    virtual Material *clone() const = 0;

    static Material_ptr create(TiXmlElement *);

private:
    static Prototypes &getPrototypes();
};

#endif // MATERIAL_H
