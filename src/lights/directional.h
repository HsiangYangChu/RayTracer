#ifndef DIRECTIONAL_H
#define DIRECTIONAL_H

#include <light.h>

class Directional: public Light
{
public:
    Directional(const std::string &);
    ~Directional() {}

    virtual vec3 getDirection(const Intersection &) const;
    virtual Color getL(const Intersection &) const;
    virtual bool inShadow(const Ray &, const Intersection &) const;
    virtual void deserialize(TiXmlElement *);
    virtual Light *clone() const
    {
        return new Directional(*this);
    }

private:
    static Directional prototype;

    float ls;
    vec3 dir;
    Color color;
};

#endif
