#ifndef MATTE_H
#define MATTE_H

#include <material.h>
#include <memory>

class Lambertian;

class Matte: public Material
{
public:
    typedef std::unique_ptr<Lambertian> Lambertian_ptr;

    Matte(const std::string &);
    Matte();
    Matte(const Matte &);
    ~Matte() {}

    virtual Color shade(const Intersection &) const;
    virtual Color areaLightShade(const Intersection &is) const;
    virtual void deserialize(TiXmlElement *);
    virtual Material *clone() const
    {
        return new Matte(*this);
    }

    void setKa(float);
    void setKd(float);
    void setCd(const Color &);

private:
    static Matte prototype;

    Lambertian_ptr ambient_brdf;
    Lambertian_ptr diffuse_brdf;
};

#endif
