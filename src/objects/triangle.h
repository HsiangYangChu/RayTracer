#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <object.h>

class Triangle: public Object
{
public:
    Triangle(const std::string &);
    ~Triangle() {}

    virtual bool hit(const Ray &, Intersection &) const;
    virtual bool shadowHit(const Ray &, FLOAT &) const;
    virtual BBox getBBox() const;
    virtual void deserialize(TiXmlElement *);
    virtual Object *clone() const
    {
        return new Triangle(*this);
    }

protected:
    vec3 v0;
    vec3 v1;
    vec3 v2;

    vec3 normal;

    BBox bbox;

private:
    static Triangle prototype;
};

#endif
