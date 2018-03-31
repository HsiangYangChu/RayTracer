#ifndef SPHERE_H
#define SPHERE_H

#include <object.h>

class Sphere: public Object
{
public:
    Sphere(const std::string &);
    ~Sphere() {}

    virtual bool hit(const Ray &, Intersection &) const;
    virtual bool shadowHit(const Ray &, FLOAT &) const;
    virtual BBox getBBox() const;
    void setCenter(const vec3 &l_c);
    void setRadius(FLOAT r);
    virtual void deserialize(TiXmlElement *);
    virtual Object *clone() const
    {
        return new Sphere(*this);
    }

private:
    static Sphere prototype;

    vec3 center;
    FLOAT r;
};

#endif
