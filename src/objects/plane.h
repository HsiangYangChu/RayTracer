#ifndef PLANE_H
#define PLANE_H

#include <object.h>

class Plane: public Object
{
public:
    Plane(const std::string &);
    Plane(const Plane&);
    ~Plane() {}

    virtual bool hit(const Ray &, Intersection &) const;
    virtual bool shadowHit(const Ray &, FLOAT &) const;
    virtual BBox getBBox() const;
    virtual void deserialize(TiXmlElement *);
    virtual Object *clone() const
    {
        return new Plane(*this);
    }

protected:
    vec3 point;
    vec3 normal;

private:
    static Plane prototype;
};

#endif
