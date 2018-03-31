#ifndef EMISSIVE_H
#define EMISSIVE_H

#include <material.h>

class Emissive: public Material
{
public:
    Emissive(const std::string &);
    Emissive();
    ~Emissive() {}

    virtual Color shade(const Intersection &) const;
    virtual Color areaLightShade(const Intersection &) const;
    virtual Color getLe(const Intersection &) const;
    virtual void deserialize(TiXmlElement *);
    virtual Material *clone() const
    {
        return new Emissive(*this);
    }

private:
    static Emissive prototype;

    float ls;
    Color ce;
};

#endif
