#ifndef PHONG_H
#define PHONG_H

#include <material.h>
#include <brdfs/lambertian.h>
#include <brdfs/glossy_specular.h>
#include <memory>

class Phong: public Material
{
public:
    typedef std::unique_ptr<Lambertian> Lambertian_ptr;
    typedef std::unique_ptr<GlossySpecular> GlossySpecular_ptr;

    Phong(const std::string &);
    Phong(const Phong &o);
    ~Phong() {}

    virtual Color shade(const Intersection &) const;
    virtual Color areaLightShade(const Intersection &) const;
    virtual void deserialize(TiXmlElement *);
    virtual Material *clone() const
    {
        return new Phong(*this);
    }

protected:
    Lambertian_ptr ambient_brdf;
    Lambertian_ptr diffuse_brdf;
    GlossySpecular_ptr specular_brdf;

private:
    static Phong prototype;
};

#endif
