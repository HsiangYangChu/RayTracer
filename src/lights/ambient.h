#ifndef AMBIENT_H
#define AMBIENT_H

#include <light.h>

class Ambient: public Light
{
public:
    Ambient(const std::string &);
    Ambient();
    ~Ambient() {}

    virtual vec3 getDirection(const Intersection &) const;
    virtual Color getL(const Intersection &) const;
    virtual void deserialize(TiXmlElement *);
    virtual Light *clone() const
    {
        return new Ambient(*this);
    }

private:
    float ls;
    Color color;

    static Ambient prototype;
};

#endif
