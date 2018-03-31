#ifndef REFLECTIVE_H
#define REFLECTIVE_H

#include <materials/phong.h>
#include <brdfs/perfect_specular.h>

class Reflective: public Phong
{
public:
    typedef std::unique_ptr<PerfectSpecular> PerfectSpecular_ptr;

    Reflective(const std::string &);
    Reflective(const Reflective &);
    ~Reflective() {}

    virtual Color shade(const Intersection &) const;
    virtual Color areaLightShade(const Intersection &is) const;
    virtual void deserialize(TiXmlElement *);
    virtual Material *clone() const
    {
        return new Reflective(*this);
    }

private:
    static Reflective prototype;

    PerfectSpecular_ptr reflective_brdf;
};

#endif
