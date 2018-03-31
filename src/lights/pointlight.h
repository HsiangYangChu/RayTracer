#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include <light.h>

class PointLight: public Light
{
public:
    PointLight(const std::string &name);
    PointLight();
    ~PointLight() {}

    virtual vec3 getDirection(const Intersection &) const;
    virtual Color getL(const Intersection &) const;
    virtual bool inShadow(const Ray &, const Intersection &) const;
    virtual void deserialize(TiXmlElement *);
    virtual Light *clone() const
    {
        return new PointLight(*this);
    }

private:
    static PointLight prototype;

    float ls;
    vec3 location;
    Color color;
};

#endif
