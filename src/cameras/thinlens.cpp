#include <cameras/thinlens.h>
#include <texture.h>
#include <world.h>
#include <ray.h>
#include <tracer.h>
#include <samplers/multi_jittered.h>

ThinLens ThinLens::prototype("ThinLens");

ThinLens::ThinLens(const std::string &name): Camera(name), f(70), lens_radius(1)
{
}

ThinLens::ThinLens(const ThinLens &o): Camera(o), lens_radius(o.lens_radius)
{
}

Camera *ThinLens::clone() const
{
    return new ThinLens(*this);
}

void ThinLens::build()
{
    const ViewPlane &vp = world.vp;
    setSampler(new MultiJittered(vp.num_samples));

    computeUVW();
}

Color ThinLens::renderPixel(uint w, uint h) const
{
    const ViewPlane &vp = world.vp;
    Color pixel_color(0);
    Ray ray;


    FLOAT inv_num_samples = 1.0 / vp.num_samples;

    for (uint j = 0; j < vp.num_samples; j++)
    {
        vec2 pp = vp.sampler->sampleUnitSquare();
        vec2 lp = sampler->sampleUnitDisk() * lens_radius;

        FLOAT x = vp.s * (w - 0.5 * vp.hres + pp.x);
        FLOAT y = vp.s * (h - 0.5 * vp.vres + pp.y);

        ray.o = eye + vec3(lp.x, lp.y, 0);
        ray.d = lensRayDirection(vec2(x, y), lp);
        pixel_color += world.tracer->traceRay(ray);
    }

    return pixel_color * float(inv_num_samples);
}

vec3 ThinLens::lensRayDirection(const vec2& pp, const vec2& lp) const
{
    vec3 p(pp.x * f / d, pp.y * f / d, -f);
    vec3 l(lp.x, lp.y, 0);

    return glm::normalize(rayDirection(p - l));
}

void ThinLens::setSampler(Sampler *l_sampler)
{
    sampler.reset(l_sampler);
    sampler->mapToUnitDisk();
}

void ThinLens::deserialize(TiXmlElement *element)
{
    TiXmlAttribute *attr = element->FirstAttribute();

    while (attr)
    {
        std::string name(attr->Name());

        if (name == "eye")
        {
            parseVec3(attr, eye);
        }
        else if (name == "look_at")
        {
            parseVec3(attr, look_at);
        }
        else if (name == "distance")
        {
            parseDouble(attr, d);
        }
        else if (name == "focal")
        {
            parseDouble(attr, f);
        }
        else if (name == "radius")
        {
            parseDouble(attr, lens_radius);
        }

        attr = attr->Next();
    }
}
