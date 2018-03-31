#ifndef TRACER_H
#define TRACER_H

#include <serializable.h>
#include <map>
#include <memory>

class World;
class Ray;

class Tracer: public Serializable
{
public:
    typedef std::map<std::string, Tracer *> Prototypes;
    typedef std::shared_ptr<Tracer> Tracer_ptr;

    Tracer(const std::string &);
    Tracer();

    ~Tracer() {}

    virtual Color traceRay(const Ray &, uint depth = 0) const = 0;
    virtual Tracer *clone() const = 0;
    virtual void deserialize(TiXmlElement *)
    {
    }

    static Tracer_ptr create(TiXmlElement *);

protected:
    const World &world;

private:
    static Prototypes &getPrototypes();
};

#endif
