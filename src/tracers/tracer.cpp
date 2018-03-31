#include <tracer.h>
#include <world.h>

Tracer::Tracer(const std::string &name): world(World::getInstance())
{
    Prototypes &prototypes = getPrototypes();

    prototypes.insert(std::make_pair(name, this));
}

Tracer::Tracer(): world(World::getInstance())
{
}

Tracer::Tracer_ptr Tracer::create(TiXmlElement *element)
{
    if (!element)
    {
        return Tracer_ptr();
    }

    Prototypes &prototypes = getPrototypes();

    std::string name(element->Value());
    auto it = prototypes.find(name);

    if (it == prototypes.end())
    {
        return Tracer_ptr();
    }

    return Tracer_ptr(it->second->clone());
}

Tracer::Prototypes &Tracer::getPrototypes()
{
    static Prototypes prototypes;

    return prototypes;
}
