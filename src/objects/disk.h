#ifndef DISK_H
#define DISK_H

#include <objects/plane.h>

class Disk: public Plane
{
public:
    Disk(const std::string &);
    Disk(const Disk &);
    ~Disk();

    virtual bool hit(const Ray &, Intersection &) const;
    virtual bool shadowHit(const Ray &, FLOAT &) const;
    virtual float pdf(const Intersection &is) const;
    virtual BBox getBBox() const;
    void sample(vec3 &, vec3 &) const;
    void setSampler(Sampler *);
    virtual void deserialize(TiXmlElement *);

    virtual Object *clone() const
    {
        return new Disk(*this);
    }

private:
    static Disk prototype;

    FLOAT min_r;
    FLOAT max_r;
    float inv_area;
    Sampler_ptr sampler;
    vec3 u;
    vec3 v;
    vec3 w;
};

#endif // DISK_H

