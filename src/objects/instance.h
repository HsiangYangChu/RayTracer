#ifndef INSTANCE_H
#define INSTANCE_H

#include <object.h>
#include <memory>

class Material;

class Instance: public Object
{
public:
    typedef std::shared_ptr<Object> Object_ptr;

    Instance(const std::string &name);
    ~Instance() {}

    virtual bool hit(const Ray &, Intersection &) const;
    virtual bool shadowHit(const Ray &, FLOAT &) const;
    virtual void sample(vec3 &, vec3 &) const;
    virtual float pdf(const Intersection &) const;
    virtual BBox getBBox() const;
    void setupBBox();

    void translate(FLOAT, FLOAT, FLOAT);
    void scale(FLOAT, FLOAT, FLOAT);
    void rotateX(FLOAT);
    void rotateY(FLOAT);
    void rotateZ(FLOAT);

    virtual void deserialize(TiXmlElement *);
    virtual Object *clone() const
    {
        return new Instance(*this);
    }

private:
    static Instance prototype;

    Object_ptr object;
    mat4 local;
    BBox bbox;
};

#endif
