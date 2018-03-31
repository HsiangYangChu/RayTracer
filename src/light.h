#ifndef LIGHT_H
#define LIGHT_H

#include <memory>
#include <serializable.h>
#include <map>

struct Intersection;
class Ray;

class Light: public Serializable
{
public:
    typedef std::map<std::string, Light *> Prototypes;
    typedef std::shared_ptr<Light> Light_ptr;

    Light(const std::string &name): shadows(true)
    {
        Prototypes &prototypes = getPrototypes();

        prototypes.insert(std::make_pair(name, this));
    }

    Light(): shadows(true)
    {
    }

    ~Light() {}

    virtual vec3 getDirection(const Intersection &) const = 0;
    virtual Color getL(const Intersection &) const = 0;

    virtual bool inShadow(const Ray &, const Intersection &) const
    {
        return false;
    }

    virtual float pdf(const Intersection &is) const
    {
        return 1;
    }

    virtual float g(const Intersection &is) const
    {
        return 1;
    }

    void setShadows(bool l_shadows)
    {
        shadows = l_shadows;
    }

    virtual Light *clone() const = 0;

    static Light_ptr create(TiXmlElement *);

protected:
    bool shadows;

private:
    static Prototypes &getPrototypes();
};


#endif // LIGHT_H
