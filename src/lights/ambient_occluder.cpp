#include <lights/ambient_occluder.h>
#include <sampler.h>
#include <intersection.h>
#include <world.h>
#include <object.h>
#include <samplers/multi_jittered.h>

AmbientOccluder AmbientOccluder::prototype("AmbientOccluder");

AmbientOccluder::AmbientOccluder(const std::string &name):
  Light(name), min_light(0), ls(1.0), color(1)
{
}

AmbientOccluder::AmbientOccluder(const AmbientOccluder &o):
    Light(o), min_light(o.min_light), ls(o.ls), color(o.color)
{
}

AmbientOccluder::~AmbientOccluder() {}

vec3 AmbientOccluder::getDirection(const Intersection &is) const
{
    vec3 up = vec3(0.0072, 1.0, 0.0034);

    vec3 w = is.normal;
    vec3 v = glm::normalize(glm::cross(w, up));
    vec3 u = glm::cross(v, w);

    vec3 sp = sampler->sampleHemisphere();

    return u * sp.x + v * sp.y + w * sp.z;
}

void AmbientOccluder::setSampler(Sampler *l_sampler)
{
    sampler.reset(l_sampler);

    sampler->mapToHemisphere(1.0);
}

Color AmbientOccluder::getL(const Intersection &is) const
{
    Ray ray(is.hit_point, getDirection(is));

    if (inShadow(ray, is))
    {
        return min_light * ls * color;
    }

    return ls * color;
}

bool AmbientOccluder::inShadow(const Ray &ray, const Intersection &is) const
{
    if (!shadows)
    {
        return false;
    }

    const World::Objects &objects = is.w.objects;
    FLOAT t;

    for (uint i = 0; i < objects.size(); i++)
    {
        if (objects[i]->shadowHit(ray, t))
        {
            return true;
        }
    }

    return false;
}

void AmbientOccluder::deserialize(TiXmlElement *element)
{
    TiXmlAttribute *attr = element->FirstAttribute();

    while (attr)
    {
        std::string name(attr->Name());

        if (name == "ls")
        {
            parseFloat(attr, ls);
        }
        else if (name == "color")
        {
            parseColor(attr, color);
        }
        else if (name == "min_light")
        {
            parseFloat(attr, min_light);
        }

        attr = attr->Next();
    }

    setSampler(new MultiJittered(World::getInstance().vp.num_samples));
}
