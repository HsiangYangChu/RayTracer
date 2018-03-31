#include <tracers/whitted.h>
#include <world.h>
#include <material.h>
#include <background.h>

Whitted Whitted::prototype("Whitted");

Whitted::Whitted(const std::string &name): Tracer(name)
{
}

Tracer *Whitted::clone() const
{
    return new Whitted(*this);
}

Color Whitted::traceRay(const Ray &ray, uint depth) const
{
    if (depth > world.vp.max_depth)
    {
        return Color(0);
    }

    Intersection is(world.hitObjects(ray));

    if (is)
    {
        is.ray = ray;
        is.depth = depth;

        return is.material->shade(is);
    }

    return world.background->getL(ray);
}
