#include <tracers/area_lighting.h>
#include <world.h>
#include <material.h>
#include <background.h>

AreaLighting AreaLighting::prototype("AreaLighting");

AreaLighting::AreaLighting(const std::string &name): Tracer(name)
{
}

Tracer *AreaLighting::clone() const
{
    return new AreaLighting(*this);
}

Color AreaLighting::traceRay(const Ray &ray, uint depth) const
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

        return is.material->areaLightShade(is);
    }

    return world.background->getL(ray);
}
