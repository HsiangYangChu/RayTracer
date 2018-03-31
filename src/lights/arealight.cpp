#include <lights/arealight.h>
#include <object.h>
#include <intersection.h>
#include <material.h>
#include <world.h>
#include <samplers/multi_jittered.h>

AreaLight AreaLight::prototype("AreaLight");

AreaLight::AreaLight(const std::string &name): Light(name)
{
}

vec3 AreaLight::getDirection(const Intersection &is) const
{
    object->sample(sample_point, normal);

    wi = glm::normalize(sample_point - is.hit_point);

    return wi;
}

Color AreaLight::getL(const Intersection &is) const
{
    if (glm::dot(normal, wi) < 0)
    {
        return material->getLe(is);
    }

    return Color(0);
}

bool AreaLight::inShadow(const Ray &ray, const Intersection &is) const
{
    if (!shadows)
    {
        return false;
    }

    const World::Objects &objects = is.w.objects;
    FLOAT t;
    FLOAT distance = glm::dot((sample_point - ray.o), ray.d);

    for (uint i = 0; i < objects.size(); i++)
    {
        if (objects[i]->shadowHit(ray, t) && t < distance)
        {
            return true;
        }
    }

    return false;
}

float AreaLight::pdf(const Intersection &is) const
{
    return object->pdf(is);
}

float AreaLight::g(const Intersection &is) const
{
    float ndotwi = glm::dot(normal, -wi);
    float d2 = glm::distance2(sample_point, is.hit_point);

    return ndotwi / d2;
}

void AreaLight::deserialize(TiXmlElement *element)
{
    element = element->FirstChildElement("object");
    assert(element);

    object = Object::create(element);
    assert(object);

    World &w = World::getInstance();

    object->setShadows(false);
    object->setSampler(new MultiJittered(w.vp.num_samples));

    material = object->getMaterial();
    assert(material);

    w.addObject(object);
}
