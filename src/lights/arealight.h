#ifndef AREALIGHT_H
#define AREALIGHT_H

#include <light.h>
#include <memory>

class Object;
class Material;

class AreaLight: public Light
{
public:
    typedef std::shared_ptr<Object> Object_ptr;
    typedef std::shared_ptr<Material> Material_ptr;

    AreaLight(const std::string &);
    ~AreaLight() {}

    virtual vec3 getDirection(const Intersection &) const;
    virtual Color getL(const Intersection &) const;
    virtual bool inShadow(const Ray &, const Intersection &) const;
    virtual float pdf(const Intersection &is) const;
    virtual float g(const Intersection &is) const;
    virtual void deserialize(TiXmlElement *);
    virtual Light *clone() const
    {
        return new AreaLight(*this);
    }

private:
    static AreaLight prototype;

    Object_ptr object;
    Material_ptr material;
    mutable vec3 sample_point;
    mutable vec3 normal;
    mutable vec3 wi;
};

#endif
