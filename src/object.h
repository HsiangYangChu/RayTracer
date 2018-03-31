#ifndef OBJECT_H
#define OBJECT_H

#include <serializable.h>
#include <memory>
#include <bbox.h>
#include <map>

struct Intersection;
struct Ray;
class Material;
class Sampler;

class Object: public Serializable
{
public:
    typedef std::shared_ptr<Material> Material_ptr;
    typedef std::unique_ptr<Sampler> Sampler_ptr;
    typedef std::map<std::string, Object *> Prototypes;
    typedef std::shared_ptr<Object> Object_ptr;

    Object(const std::string &);
    Object();
    Object(const Object &);

    ~Object() {}

    virtual Object *clone() const
    {
        return NULL;
    }

    virtual bool hit(const Ray &, Intersection &) const = 0;
    virtual bool shadowHit(const Ray &, FLOAT &) const = 0;
    virtual void sample(vec3 &, vec3 &) const;
    virtual float pdf(const Intersection &is) const;
    virtual BBox getBBox() const;
    virtual vec3 getNormal() const;

    Material_ptr getMaterial() const;
    virtual void setMaterial(const Material_ptr &);
    virtual void setSampler(Sampler *);
    void setShadows(bool);

    static Object_ptr create(TiXmlElement *);
    static Object_ptr createFromWrapper(TiXmlElement *);

protected:
    mutable Material_ptr material;
    bool shadows;

private:
    static Prototypes &getPrototypes();
};

#endif // OBJECT_H
