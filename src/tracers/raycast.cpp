#include <tracers/raycast.h>
#include <material.h>
#include <background.h>
#include <intersection.h>
#include <world.h>

RayCast RayCast::prototype("RayCast");

RayCast::RayCast(const std::string &name): Tracer(name)
{
}

RayCast::RayCast()
{
}

Tracer *RayCast::clone() const
{
    return new RayCast(*this);
}

Color RayCast::traceRay(const Ray &ray, uint depth) const
{
    Intersection is(world.hitObjects(ray));

    if (is)
    {
        is.ray = ray;
        return is.material->shade(is);
    }

    return world.background->getL(ray);
}
