#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <memory>
#include <serializable.h>
#include <ray.h>
#include <map>

class Background: public Serializable
{
public:
    typedef std::shared_ptr<Background> Background_ptr;
    typedef std::map<std::string, Background *> Prototypes;

    ~Background() {}

    Background(const std::string &name)
    {
        getPrototypes().insert(std::make_pair(name, this));
    }

    Background()
    {
    }

    virtual Color getL(const Ray &) const = 0;

    virtual Background *clone() const = 0;

    static Background_ptr create(TiXmlElement *);

private:
    static Prototypes &getPrototypes();
};

#endif
