#ifndef COMPOUND_H
#define COMPOUND_H

#include <object.h>
#include <memory>
#include <vector>

class Compound: public Object
{
public:
    typedef std::shared_ptr<Object> Object_ptr;
    typedef std::vector<Object_ptr> Objects;

    Compound(const std::string &);
    Compound();
    ~Compound() {}

    void addObject(Object *);
    void addObject(const Object_ptr &);
    virtual void setMaterial(const Material_ptr &);
    virtual bool hit(const Ray &, Intersection &) const;
    virtual bool shadowHit(const Ray &, FLOAT &) const;
    virtual BBox getBBox() const;
    void recalcBBox(Object *);
    virtual void deserialize(TiXmlElement *)
    {
    }

protected:
    Objects objects;
    BBox bbox;
    bool is_bbox_set;
};

#endif
